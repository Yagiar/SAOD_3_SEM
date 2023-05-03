#include <iostream>
#include "SufTree.h"

using namespace std;

/// <summary>
/// Достраивает дерево, добавляя очередной символ из входного потока
/// </summary>
/// <param name="phase">номер символа входного потока, который добавялется в дерево</param>
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
}
