#include <iostream>
#include "SufTree.h"

using namespace std;

/// <summary>
/// ����������� ������, �������� ��������� ������ �� �������� ������
/// </summary>
/// <param name="phase">����� ������� �������� ������, ������� ����������� � ������</param>
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
}
