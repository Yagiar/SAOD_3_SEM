#include "Edge.h"
#include "Node.h"

bool Edge::isLeaf() {
	return node == nullptr || node->leaf;
}
