#ifndef ZNODE_HPP_
#define ZNODE_HPP_

#include "Z_Obj.hpp"
#include <string>
#include <cstdlib>
using namespace std;

class ZNode {
	friend class AVLTree;
	friend class ZDatabase;
	Z_Obj *zip;
	int height; // max(left->height,right->height) + 1
	ZNode *left;
	ZNode *right;
	ZNode *parent;
public:
	void printZNode();
	ZNode(Z_Obj *z);
	ZNode();
};

#endif /* ZNODE_HPP_ */
