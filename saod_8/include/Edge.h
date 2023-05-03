#pragma once

class Node;

class Edge {

public:
	int start;
	int end;		// -1 - use last input position
	Node* node = nullptr;

	int sufIdx = -1; //��� ����� ��������� ������ ������ �������� �� ������� ������. ��� ���������� �����.


	Edge() : start(-1), end(-1) {}
	Edge(int s, int e = -1) : start(s), end(e) {}
	bool isLeaf();
};

