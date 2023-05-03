#pragma once
#include <map>
#include <set>
#include "Edge.h"

class Node {
public:
int id; // for visualization
std::map<char, Edge> children;
bool leaf = false;
Node* suffix_link = nullptr;
int pathLen = 0;
std::set<int> idx;
std::set<int> revIdx;
Node(int id) : id(id) {}
};
