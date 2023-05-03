#include <iostream>
#include "SufTree.h"

using namespace std;

/// <summary>
/// Достраивает дерево, добавляя очередной символ из входного потока
/// </summary>
/// <param name="phase">номер символа входного потока, который добавялется в дерево</param>
void SufTree::FillPath() {
    fillPath(root, 0);
}
void SufTree::FillNodes()
{
    fillNodes(root);
}

void SufTree::fillNodes(Node* node)
{
    // если узел является листом, добавляем его индекс или реверс-индекс в соответствующий набор
    if (node->leaf) {
        int leafIdx = node->children.begin()->second.start;
        if (leafIdx < modT) {
            node->idx.insert(leafIdx);
        }
        else {
            node->revIdx.insert(modT * 2 - leafIdx - 1);
        }
        return;
    }

    // обрабатываем дочерние узлы
    for (auto& pair : node->children) {
        Node* child = pair.second.node;
        fillNodes(child);
        // добавляем индексы и реверс-индексы из дочернего узла
        node->idx.insert(child->idx.begin(), child->idx.end());
        node->revIdx.insert(child->revIdx.begin(), child->revIdx.end());
    }
}

void SufTree::fillPath(Node* n, int pLen) {
    n->pathLen = pLen;

    for (auto it = n->children.begin(); it != n->children.end(); ++it) {
        Edge edge = it->second;
        Node* child = edge.node;

        fillPath(child, pLen + (edge.end - edge.start) + 1);
    }
}
int SufTree::MaxPalindromeLen() {
    int maxLen = 0;
    findPalindromeLen(root, maxLen);
    return maxLen;
}

int SufTree::findPalindromeLen(Node* n, int& maxLen) {
    int len = 0;
    if (!n->idx.empty()) {
        for (int i : n->idx) {
            int j = *n->revIdx.lower_bound(modT - i - 1);
            if (i + j == modT - 1) {  // найден палиндром
                len = j - i + 1;
                maxLen = max(maxLen, len);
            }
        }
    }
    for (auto& child : n->children) {
        len = max(len, findPalindromeLen(child.second.node, maxLen));
    }
    return len;
}

void SufTree::GetPalindromes(std::list<int>& res, int len) {
  getMaxPalindromes(root, res, len);
}

void SufTree::getMaxPalindromes(Node* n, std::list<int>& res, int len) {
  if (n == nullptr || n == root || n->pathLen < len) {
    return;
  }
  if (n->pathLen == len) {
    for (int idx : n->idx) {
      if (std::find(n->revIdx.begin(), n->revIdx.end(), idx) != n->revIdx.end()) {
        res.push_back(idx - len);
      }
    }
    return;
  }
  for (auto& child : n->children) {
    getMaxPalindromes(child.second.node, res, len);
  }
}

void SufTree::extend(int phase)
{
    // установить lastCreatedNode = null перед началом каждой фазы
    Node *lastCreatedNode = nullptr;

    // Это движущийся конец листьев. Возможно, как-то упростится.
    // Сейчас нужен для вычисления длины листовых ребер.
    last_read = phase;

    // сколько суффиксов осталось встроить. (Все предыдущие + 1 из последнего входного символа)
    remainder++;

    // Перебираем все недостроенные суффиксы!
    while (remainder > 0)
    {
        // если ap.length равна 0, тогда ищем текущий символ непосредственно из узла (не на ребре).
        if (ap.length == 0)
            ap.edge = phase; // индекс текущего символа в тексте определяет ребро, по которому будем двигаться

        // ищем ребро активного узла, которое начинается на эту букву
        auto find = ap.node->children.find(input[ap.edge]);

        // не нашли
        if (find == ap.node->children.end())
        {
            // добавим новое ребро в активный узел
            ap.node->children[input[ap.edge]] = Edge(phase);
            if (lastCreatedNode != nullptr) {
                lastCreatedNode->suffix_link = ap.node;
                lastCreatedNode = nullptr;
            }
        }
        // если ребро из ap.node есть, будем двигаться по нему
        else
        {
            Edge &e = find->second;
            int edge_length = edgeLen(e);

            // ребра короткие.
            if (ap.length >= edge_length)
            {
                ap.edge += edge_length;
                ap.length -= edge_length;
                ap.node = e.node;

                continue; // таким образом мы будем спускаться, пока не станет ap.length < edge_length.
                          // Т.е. пока активная точка не окажется внутри текущего ребра.
            }

            // правило 3: если текущий символ есть на ребре,
            // т.е. суффикс уже есть в дереве, то просто увеличим ap.length
            // как бы "шагнем вперед" по ребру и из предыдущего узла сошлемся на текущий.
            if (input[e.start + ap.length] == input[phase])
            {
                // если lastCreatedNode != null значит уже вставляли узел на этой фазе
                // установим suffix_link на ap.node
                if (lastCreatedNode != nullptr && ap.node != root)
                    lastCreatedNode->suffix_link = ap.node;
                ap.length++;
                break; // выйдем из цикла while, т.е.  не уменьшим remainder - количество неявных суффиксов.
            }

            // сюда попали, если текущего символа нет на дуге
            // создадим новую внутреннюю вершинку
            Node* split = new Node(node_count++);
            // запомним, где кончается текущее ребро и его целевой узел
            int end = e.end;
            Node* pnode = e.node;

            // Сдвигаем конец текущего ребра
            e.end = e.start + ap.length-1;
            // И связываем его с новым узлом
            e.node = split;

            // Создадим остаток остаток активного ребра (конец и целевой узел)
            Edge tail(e.start + ap.length, end);
            tail.node = pnode;
            // Добавим остаток во вновь созданный узел
            split->children[input[e.start + ap.length]] = tail;

            // и ребро из последнего символа
            split->children[input[phase]] = Edge(phase);
            // На этой фазе уже создавался внутрениий узел. Из него сошлемся на split
            if (lastCreatedNode != nullptr)
            {
                lastCreatedNode->suffix_link = split;
            }

            lastCreatedNode = split;
        }

        // Здесь один суффикс обработан! Осталось меньше.
        remainder--;
        // если ap.node == root, тогда согласно правилу 2, мы декр. ap.length и инкр. ap.edge
        if (ap.node == root && ap.length > 0)
        {
            ap.length--;
            ap.edge++;
        }
        else if (ap.node != root && ap.node->suffix_link != nullptr) // если же activeNode != root, то радостно скачем по имеющейся суффиксной ссылке
        {
            ap.node = ap.node->suffix_link;
        }
        else
        {
            ap.node = root;
        }
    }
}

/// <summary>
/// Добавляет все неявные суффиксы, делая их явными.
/// </summary>
void SufTree::finalize()
{
    // установить lastCreatedNode = null перед началом каждой фазы
    Node* lastCreatedNode = nullptr;

    /// !!! сделаем так! Будет признак, как будто добавлен уникальный символ!
    /// Это автоматически привело бы к завершению дерева!
    int phase = -1;
    modT = last_read + 1;
    // Перебираем все недостроенные суффиксы!
    while (remainder > 0)
    {
        // !!! Это ситуация, когда ребро закончилось вместе с текуще длиной. См. ниже!!!
        // если ap.length равна 0, тогда ищем текущий символ непосредственно из узла (не на ребре).
        if (ap.length == 0)
            ap.edge = phase; // индекс текущего символа в тексте определяет ребро, по которому будем двигаться

        // ищем ребро активного узла, которое начинается на эту букву

        // !!! Обрабтаем возможную ситуацию с ap.edge == -1;
        auto find = ap.node->children.end();
        if(ap.edge>=0)
            find = ap.node->children.find(input[ap.edge]);

        // не нашли
        if (find == ap.node->children.end())
        {
            // Добавим в узел признак leaf.
            // Вместо ap.node->children[input[ap.edge]] = Edge(phase); - добавления ребра из уникального символа
            // Если он установлен, значит ребро, которое заканчивается в этом узле - лист!
            if(ap.node != root)
                ap.node->leaf = true;
            if (lastCreatedNode != nullptr) {
                lastCreatedNode->suffix_link = ap.node;
                lastCreatedNode = nullptr;
            }
        }
        // если ребро из ap.node есть, будем двигаться по нему
        else
        {
            Edge& e = find->second;
            int edge_length = edgeLen(e);

            // ребра короткие.
            if (ap.length >= edge_length)
            {
                ap.edge += edge_length;
                ap.length -= edge_length;
                ap.node = e.node;

                continue; // таким образом мы будем спускаться, пока не станет ap.length < edge_length.
                          // Т.е. пока активная точка не окажется внутри текущего ребра.
            }

            // правило 3: если текущий символ есть на ребре,
            // т.е. суффикс уже есть в дереве, то просто увеличим ap.length
            // как бы "шагнем вперед" по ребру и из предыдущего узла сошлемся на текущий.
            if (e.start + ap.length == last_read + 1)
            {
                // если lastCreatedNode != null значит уже вставляли узел на этой фазе
                // установим suffix_link на ap.node
                if (lastCreatedNode != nullptr && ap.node != root)
                    lastCreatedNode->suffix_link = ap.node;
                ap.length++;
                break; // выйдем из цикла while, т.е.  не уменьшим remainder - количество неявных суффиксов.
            }

            // сюда попали, если текущего символа нет на дуге
            // создадим новый узел
            Node* split = new Node(node_count++);
            // запомним, где кончается текущее ребро и его целевой узел
            int end = e.end;
            Node* pnode = e.node;

            // Сдвигаем конец текущего ребра
            e.end = e.start + ap.length - 1;
            // И связываем его с новым узлом
            e.node = split;

            // Создадим остаток остаток активного ребра (конец и целевой узел)
            Edge tail(e.start + ap.length, end);
            tail.node = pnode;
            // Добавим остаток во вновь созданный узел
            split->children[input[e.start + ap.length]] = tail;

            //Не будем добавлять ребро из уникального символа,
            // а как и раньше, просто сделаем узел "листовым".
            split->leaf = true;
            // На этой фазе уже создавался внутрениий узел. Из него сошлемся на split
            if (lastCreatedNode != nullptr)
            {
                lastCreatedNode->suffix_link = split;
            }

            lastCreatedNode = split;
        }

        // Здесь один суффикс обработан! Осталось меньше.
        remainder--;
        // если ap.node == root, тогда согласно правилу 2, мы декр. ap.length и инкр. ap.edge
        if (ap.node == root && ap.length > 0)
        {
            ap.length--;
            ap.edge++;
        }
        else if (ap.node != root && ap.node->suffix_link != nullptr) // если же activeNode != root, то радостно скачем по имеющейся суффиксной ссылке
        {
            ap.node = ap.node->suffix_link;
        }
        else
        {
            ap.node = root;
        }
    }
    FillLeaves();   // Заполнение sufIdx у листьев
    FillPath();
}
