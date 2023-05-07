#include <iostream>	// �����, �.�. ���� ������ ������������
#include <map>		// ��� �������� ����� ������� � �������� �����
#include "Edge.h"
#include "Node.h"
using namespace std;

/// <summary>
/// For Ukkonen algorithm
/// Represents Active Point (state machine)
/// </summary>
class ActivePoint {
public:
	Node* node;		// ������� �������� ����
	int edge = -1;	// ������� �������� ����� � �������� ����
	int length;		// ����� �� ��������� �����
};

class SufTree {
	const char* input;				// ����� ��� ����������� T
	int last_read = -1;				// ���������� ����������� ������
	Node* lastCreatedNode = nullptr;

	int node_count = 0;					// ������� ��� ������� id-����.
	Node* root = new Node(node_count++);

	int remainder = 0;					// ���������� ��������� ��� �� ����������� ����, �� ��� �������������� � ������.
	ActivePoint ap = { root, -1, 0 };	// {������� ����, �������� ����� � ����, ����� �� ��������� �����}
public:

	SufTree(const char* inp) :input(inp){}
	SufTree(const SufTree&) = delete;			// ��������� �����������, ����� ������������ ��������
	SufTree& operator=(const SufTree&) = delete;// ��������� �������������.

	// ��� ��� �����������
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
	// ������ ���������� ������
	void extend(int i);
	void finalize();

	// ����� �����, �.�. ����� ������ ���������� ������������� �������.
	int edgeLen(Edge& e) {
		return e.end >= 0 ? e.end - e.start + 1 : last_read - e.start + 1;
	}
private:

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
	int fillMin(Node* n, int len)
	{
		int minIdx = -1;
		for (auto& p : n->children)
		{
			int _len = len + edgeLen(p.second);
			int idX = -1;
			if (p.second.isLeaf()) {
				idX = last_read - _len + 1;
			}
			if (idX < minIdx || minIdx == -1) {
				minIdx = idX;
			}
			if (p.second.node) {
				idX = fillMin(p.second.node, _len);
			}
			if (idX < minIdx || minIdx == -1) {
				minIdx = idX;
			}
		}
		n->minIdx = minIdx;
		return n->minIdx;
	}
	int fillMax(Node* n, int len)
	{
		int maxIdx = -1;
		for (auto& p : n->children)
		{
			int _len = edgeLen(p.second);
			int idX = -1;
			if (p.second.isLeaf()) {
				idX = last_read - _len + 1;
			}
			if (idX > maxIdx || maxIdx == -1) {
				maxIdx = idX;
			}
			if (p.second.node) {
				idX = fillMax(p.second.node, _len);
			}
			if (idX > maxIdx || maxIdx == -1) {
				maxIdx = idX;
			}
		}
		n->maxIdx = maxIdx;
		return n->maxIdx;
	}
	void fillMaxLen(Node* n, int len) {
	//	std::size_t maxIdx = -1;
		(*n).maxLen = min(len, (*n).maxIdx - (*n).minIdx);
		for (auto& p : n->children)
		{
			int _len = len + edgeLen(p.second);
			if (p.second.node) {
				fillMaxLen(p.second.node, _len);
			}
		}
	}
	Node* getMax(Node* n) {
		Node* max = n;
		Node* n2 = NULL;
		for (auto& p : n->children)
		{
			if (p.second.node != nullptr) {
				n2 = getMax(p.second.node);
			}
			if (n2 != NULL && (*n2).maxLen > (*max).maxLen) {
				max = n2;
			}
		}
		return max;
	}
public:
	void FillLeaves() {
		fillLeaves(root, 0);
	}
	void FillMin() {
		fillMin(root, 0);
	}
	void FillMax() {
		fillMax(root, 0);
	}
	void FillMaxLen() {
		fillMaxLen(root, 0);
	}
	Node* GetMax() {
		return getMax(root);
	}

private:
	// ������ ������������
	/// <summary>
	/// ������������� �������� ����� (����� ��������� ��������)
	/// </summary>
	void showActivePoint() {
		if (ap.edge >= 0)
			cout << '(' << ap.node->id << ", " << input[ap.edge] << ", " << ap.length << ')';
		else
			cout << '(' << ap.node->id << ", " << "undef, " << ap.length << ')';
	}
	/// <summary>
	/// ������������� �����
	/// </summary>
	/// <param name="e">������ �� �����</param>
	/// <param name="level">������� ����� � ������</param>
	void showEdge(Edge& e, int level)
	{
		for (int i = 0; i < edgeLen(e); i++)
			cout << input[e.start + i];
		if(e.isLeaf())
			cout << '|' << e.sufIdx;	// ������ ����� ����������� ����� � ����
		cout << endl;
	}
	/// <summary>
	/// ������������ ����
	/// </summary>
	/// <param name="n">��������� �� ����</param>
	/// <param name="level">������� ���� � ������</param>
	void showNode(Node* n, int level) {
		string shift(level, '\t');
		cout << shift << n->id;
		if (n->suffix_link)
			cout << " --> " << n->suffix_link->id;
		cout << ", minIdx: " << n->minIdx <<", maxIdx: " << n->maxIdx <<", maxLen: "<<n->maxLen << endl;
		for (auto e : n->children) {
			cout <<shift << "    ";
			showEdge(e.second, level);
			if (e.second.node != nullptr)
				showNode(e.second.node, level+1);
		}
	}

public:
	void ShowTree()
	{
		showNode(root, 0);
	}

};
