#include <iostream>
#include "SufTree.h"

using namespace std;

/// <summary>
/// ����������� ������, �������� ��������� ������ �� �������� ������
/// </summary>
/// <param name="phase">����� ������� �������� ������, ������� ����������� � ������</param>
void SufTree::FillPath() {
    fillPath(root, 0);
}
void SufTree::FillNodes()
{
    fillNodes(root);
}

void SufTree::fillNodes(Node* node)
{
    // ���� ���� �������� ������, ��������� ��� ������ ��� ������-������ � ��������������� �����
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

    // ������������ �������� ����
    for (auto& pair : node->children) {
        Node* child = pair.second.node;
        fillNodes(child);
        // ��������� ������� � ������-������� �� ��������� ����
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
            if (i + j == modT - 1) {  // ������ ���������
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
    // ���������� lastCreatedNode = null ����� ������� ������ ����
    Node *lastCreatedNode = nullptr;

    // ��� ���������� ����� �������. ��������, ���-�� ����������.
    // ������ ����� ��� ���������� ����� �������� �����.
    last_read = phase;

    // ������� ��������� �������� ��������. (��� ���������� + 1 �� ���������� �������� �������)
    remainder++;

    // ���������� ��� ������������� ��������!
    while (remainder > 0)
    {
        // ���� ap.length ����� 0, ����� ���� ������� ������ ��������������� �� ���� (�� �� �����).
        if (ap.length == 0)
            ap.edge = phase; // ������ �������� ������� � ������ ���������� �����, �� �������� ����� ���������

        // ���� ����� ��������� ����, ������� ���������� �� ��� �����
        auto find = ap.node->children.find(input[ap.edge]);

        // �� �����
        if (find == ap.node->children.end())
        {
            // ������� ����� ����� � �������� ����
            ap.node->children[input[ap.edge]] = Edge(phase);
            if (lastCreatedNode != nullptr) {
                lastCreatedNode->suffix_link = ap.node;
                lastCreatedNode = nullptr;
            }
        }
        // ���� ����� �� ap.node ����, ����� ��������� �� ����
        else
        {
            Edge &e = find->second;
            int edge_length = edgeLen(e);

            // ����� ��������.
            if (ap.length >= edge_length)
            {
                ap.edge += edge_length;
                ap.length -= edge_length;
                ap.node = e.node;

                continue; // ����� ������� �� ����� ����������, ���� �� ������ ap.length < edge_length.
                          // �.�. ���� �������� ����� �� �������� ������ �������� �����.
            }

            // ������� 3: ���� ������� ������ ���� �� �����,
            // �.�. ������� ��� ���� � ������, �� ������ �������� ap.length
            // ��� �� "������ ������" �� ����� � �� ����������� ���� �������� �� �������.
            if (input[e.start + ap.length] == input[phase])
            {
                // ���� lastCreatedNode != null ������ ��� ��������� ���� �� ���� ����
                // ��������� suffix_link �� ap.node
                if (lastCreatedNode != nullptr && ap.node != root)
                    lastCreatedNode->suffix_link = ap.node;
                ap.length++;
                break; // ������ �� ����� while, �.�.  �� �������� remainder - ���������� ������� ���������.
            }

            // ���� ������, ���� �������� ������� ��� �� ����
            // �������� ����� ���������� ��������
            Node* split = new Node(node_count++);
            // ��������, ��� ��������� ������� ����� � ��� ������� ����
            int end = e.end;
            Node* pnode = e.node;

            // �������� ����� �������� �����
            e.end = e.start + ap.length-1;
            // � ��������� ��� � ����� �����
            e.node = split;

            // �������� ������� ������� ��������� ����� (����� � ������� ����)
            Edge tail(e.start + ap.length, end);
            tail.node = pnode;
            // ������� ������� �� ����� ��������� ����
            split->children[input[e.start + ap.length]] = tail;

            // � ����� �� ���������� �������
            split->children[input[phase]] = Edge(phase);
            // �� ���� ���� ��� ���������� ���������� ����. �� ���� �������� �� split
            if (lastCreatedNode != nullptr)
            {
                lastCreatedNode->suffix_link = split;
            }

            lastCreatedNode = split;
        }

        // ����� ���� ������� ���������! �������� ������.
        remainder--;
        // ���� ap.node == root, ����� �������� ������� 2, �� ����. ap.length � ����. ap.edge
        if (ap.node == root && ap.length > 0)
        {
            ap.length--;
            ap.edge++;
        }
        else if (ap.node != root && ap.node->suffix_link != nullptr) // ���� �� activeNode != root, �� �������� ������ �� ��������� ���������� ������
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
/// ��������� ��� ������� ��������, ����� �� ������.
/// </summary>
void SufTree::finalize()
{
    // ���������� lastCreatedNode = null ����� ������� ������ ����
    Node* lastCreatedNode = nullptr;

    /// !!! ������� ���! ����� �������, ��� ����� �������� ���������� ������!
    /// ��� ������������� ������� �� � ���������� ������!
    int phase = -1;
    modT = last_read + 1;
    // ���������� ��� ������������� ��������!
    while (remainder > 0)
    {
        // !!! ��� ��������, ����� ����� ����������� ������ � ������ ������. ��. ����!!!
        // ���� ap.length ����� 0, ����� ���� ������� ������ ��������������� �� ���� (�� �� �����).
        if (ap.length == 0)
            ap.edge = phase; // ������ �������� ������� � ������ ���������� �����, �� �������� ����� ���������

        // ���� ����� ��������� ����, ������� ���������� �� ��� �����

        // !!! ��������� ��������� �������� � ap.edge == -1;
        auto find = ap.node->children.end();
        if(ap.edge>=0)
            find = ap.node->children.find(input[ap.edge]);

        // �� �����
        if (find == ap.node->children.end())
        {
            // ������� � ���� ������� leaf.
            // ������ ap.node->children[input[ap.edge]] = Edge(phase); - ���������� ����� �� ����������� �������
            // ���� �� ����������, ������ �����, ������� ������������� � ���� ���� - ����!
            if(ap.node != root)
                ap.node->leaf = true;
            if (lastCreatedNode != nullptr) {
                lastCreatedNode->suffix_link = ap.node;
                lastCreatedNode = nullptr;
            }
        }
        // ���� ����� �� ap.node ����, ����� ��������� �� ����
        else
        {
            Edge& e = find->second;
            int edge_length = edgeLen(e);

            // ����� ��������.
            if (ap.length >= edge_length)
            {
                ap.edge += edge_length;
                ap.length -= edge_length;
                ap.node = e.node;

                continue; // ����� ������� �� ����� ����������, ���� �� ������ ap.length < edge_length.
                          // �.�. ���� �������� ����� �� �������� ������ �������� �����.
            }

            // ������� 3: ���� ������� ������ ���� �� �����,
            // �.�. ������� ��� ���� � ������, �� ������ �������� ap.length
            // ��� �� "������ ������" �� ����� � �� ����������� ���� �������� �� �������.
            if (e.start + ap.length == last_read + 1)
            {
                // ���� lastCreatedNode != null ������ ��� ��������� ���� �� ���� ����
                // ��������� suffix_link �� ap.node
                if (lastCreatedNode != nullptr && ap.node != root)
                    lastCreatedNode->suffix_link = ap.node;
                ap.length++;
                break; // ������ �� ����� while, �.�.  �� �������� remainder - ���������� ������� ���������.
            }

            // ���� ������, ���� �������� ������� ��� �� ����
            // �������� ����� ����
            Node* split = new Node(node_count++);
            // ��������, ��� ��������� ������� ����� � ��� ������� ����
            int end = e.end;
            Node* pnode = e.node;

            // �������� ����� �������� �����
            e.end = e.start + ap.length - 1;
            // � ��������� ��� � ����� �����
            e.node = split;

            // �������� ������� ������� ��������� ����� (����� � ������� ����)
            Edge tail(e.start + ap.length, end);
            tail.node = pnode;
            // ������� ������� �� ����� ��������� ����
            split->children[input[e.start + ap.length]] = tail;

            //�� ����� ��������� ����� �� ����������� �������,
            // � ��� � ������, ������ ������� ���� "��������".
            split->leaf = true;
            // �� ���� ���� ��� ���������� ���������� ����. �� ���� �������� �� split
            if (lastCreatedNode != nullptr)
            {
                lastCreatedNode->suffix_link = split;
            }

            lastCreatedNode = split;
        }

        // ����� ���� ������� ���������! �������� ������.
        remainder--;
        // ���� ap.node == root, ����� �������� ������� 2, �� ����. ap.length � ����. ap.edge
        if (ap.node == root && ap.length > 0)
        {
            ap.length--;
            ap.edge++;
        }
        else if (ap.node != root && ap.node->suffix_link != nullptr) // ���� �� activeNode != root, �� �������� ������ �� ��������� ���������� ������
        {
            ap.node = ap.node->suffix_link;
        }
        else
        {
            ap.node = root;
        }
    }
    FillLeaves();   // ���������� sufIdx � �������
    FillPath();
}
