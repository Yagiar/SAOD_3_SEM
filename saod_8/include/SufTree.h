#pragma once
#include <iostream>	// Нужно, т.к. есть методы визуализации
#include <map>		// для хранения ребер ведущих к дочерним узлам
#include "Edge.h"
#include "Node.h"
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;

class ActivePoint {
public:
	Node* node;		// Текущий активный узел
	int edge = -1;	// Текущее активное ребро в активном узле
	int length;		// Длина по активному ребру
};

class SufTree {
	const char* input;				// Буфер где заполняется T
	int last_read = -1;				// Количество прочитанных байтов
	Node* lastCreatedNode = nullptr;

	int node_count = 0;					// Счетчик для задания id-узла.
	Node* root = new Node(node_count++);
    int modT = 0;
	int remainder = 0;					// Количестов суффиксов еще не добавленных явно, но уже присутствующих в дереве.
	ActivePoint ap = { root, -1, 0 };	// {текущий узел, активное ребро в узле, длина по активному ребру}
public:
    void FillNodes();
    int MaxPalindromeLen();
	SufTree(const char* inp) :input(inp)
	{

	string reversed(inp);
    reverse(reversed.begin(), reversed.end());
    input = (char*)realloc((void*)input, strlen(input) + strlen(reversed.c_str()) + 1);
    strcat((char*)input, reversed.c_str());

    }
	SufTree(const SufTree&) = delete;			// Запретили копирование, чтобы пользовались ссылками
	SufTree& operator=(const SufTree&) = delete;// Запретили присванивание.

	// все для деструктора
	void deleteEdge(Edge& e) {
		if (e.node)
			deleteNode(e.node);
	}

	void deleteNode(Node* n) {
		for (auto& c : n->children)
		{
			deleteEdge(c.second);
		}
		delete n;
	}
	~SufTree() {
		deleteNode(root);
	}
	// Методы построения дерева
	void extend(int i);
	void finalize();
    void GetPalindromes(std::list<int>& res, int len);
	// Лучше здесь, т.к. нужен индекс последнего прочитаннного смивола.
	int edgeLen(Edge& e) {
		return e.end >= 0 ? e.end - e.start + 1 : last_read - e.start + 1;
	}
#pragma region Прикладные методы
private:
    void getMaxPalindromes(Node* n, std::list<int>& res, int len);
    void fillNodes(Node* node);
    int findPalindromeLen(Node* n, int& maxLen);
    void fillPath(Node* node, int endIndex);
	void fillLeaves(Node* n, int len)
	{
		for (auto& p : n->children)
		{
			int _len = len + edgeLen(p.second);
			if (p.second.isLeaf()) {
				p.second.sufIdx = last_read - _len + 1;
			}
			if (p.second.node)
				fillLeaves(p.second.node, _len);
		}
	}
public:
	void FillLeaves() {
		fillLeaves(root, 0);
	}
#pragma endregion
private:

	void showActivePoint() {
		if (ap.edge >= 0)
			cout << '(' << ap.node->id << ", " << input[ap.edge] << ", " << ap.length << ')';
		else
			cout << '(' << ap.node->id << ", " << "undef, " << ap.length << ')';
	}
	void showEdge(Edge& e, int level)
	{
		for (int i = 0; i < edgeLen(e); i++)
			cout << input[e.start + i];
		if(e.isLeaf())
			cout << '|' << e.sufIdx;	// Значит ребро представлет собой и лист
		cout << endl;
	}

	void showNode(Node* n, int level, int len, int modT) {
    string shift(level, '\t');
    if (n == root)
        cout << "|T| = " << modT << endl;
    cout << shift << n->id << " (" << len << ") ";

    // Выводим idx и revIdx
    if (!n->children.empty()) {
        cout << "(";
        for (int idx : n->idx) {
            cout << idx << " ";
        }
        cout << ") [";
        for (int idx : n->revIdx) {
            cout << idx << " ";
        }
        cout << "]";
    }

    if (n->suffix_link)
        cout << " --> " << n->suffix_link->id;
    cout << endl;

    for (auto e : n->children) {
        cout << shift << "    ";
        showEdge(e.second, level);
        if (e.second.node != nullptr)
            showNode(e.second.node, level + 1, len + edgeLen(e.second), modT);
    }
}

public:
    void FillPath();
	void ShowTree()
	{
		showNode(root, 0,0,modT);
	}

};
