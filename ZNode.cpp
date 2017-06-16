#include <iostream>
#include <string>
#include "Z_Obj.hpp"
#include "ZNode.hpp"

using namespace std;

ZNode::ZNode(Z_Obj *z):zip(z) {
    height = 1;
    parent = NULL;
    right = NULL;
    left = NULL;
}

ZNode::ZNode(){
    zip = NULL;
    parent = NULL;
    right = NULL;
    left = NULL;
    height = 0;
}

void ZNode::printZNode(){
    cout << *zip << endl;
}