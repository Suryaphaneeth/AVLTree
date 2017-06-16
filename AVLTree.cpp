#include <iostream>
#include <algorithm>
#include "AVLTree.hpp"
#include "Z_Obj.hpp"
#include "ZNode.hpp"

using namespace std;

AVLTree::AVLTree(){
    root = NULL;
    AVLflag = false;
}

AVLTree::AVLTree(bool flag):AVLflag(flag){
    root = NULL;
}

ZNode* AVLTree::findZip(int z, ZNode* n){
    if(n != NULL){
        if(n -> zip -> zip == z)
            return n;
        else if(z < n -> zip -> zip)
            return (findZip(z, n -> left));
        else if(z > n -> zip -> zip)
            return (findZip(z, n -> right));
    }
    return NULL;
}

void AVLTree::addNode( Z_Obj *n, ZNode *r){
    if(r != NULL){
        if(*n < *(r -> zip)){
            if(r -> left == NULL){
                r -> left = new ZNode(n);
                r -> left -> parent = r;
                if(AVLflag)
                    adjustBalances(r);
            }
            else 
                addNode(n, r -> left); 
        }
        else{
            if(r -> right == NULL){
                r -> right = new ZNode(n);
                r -> right -> parent = r;
                if(AVLflag)
                    adjustBalances(r);
            }
            else 
                addNode(n, r -> right);            
        } 
    }
    else{
        ZNode* tmp = new ZNode(n);
        root = tmp;
    }
}

void AVLTree::adjustBalances(ZNode* n){
    ZNode* prnt = new ZNode();
    prnt = n -> parent;
    if(height(n -> left) > height(n -> right) + 1)
        rebalanceRight(n);
    else if(height(n -> right) > height(n -> left) + 1)
        rebalanceLeft(n);
    adjustHeight(n);
    if(prnt != NULL)
        adjustBalances(prnt);
}

void AVLTree::adjustHeight(ZNode *n){
    n -> height = 1 + max(height(n -> left), height(n -> right));
}

int AVLTree::height(ZNode *n){
    if(n == NULL)
        return 0;
    else
        return (1 + max(height(n -> left), height(n -> right)));
}

void AVLTree::rebalanceRight(ZNode* n){
    ZNode* childrenNode = new ZNode();
    childrenNode = n -> left;
    if(height(childrenNode -> right) > height(childrenNode -> left))
        rotateLeft(childrenNode);
    rotateRight(n);
    adjustHeight(childrenNode);
    adjustHeight(n);
    
}

void AVLTree::rebalanceLeft(ZNode* n){
    ZNode* childNode = new ZNode();
    childNode = n -> right;
    if(height(childNode -> left) > height(childNode -> right)){
        rotateRight(childNode);
    }
    rotateLeft(n);
    adjustHeight(childNode);
    adjustHeight(n);
}

ZNode* AVLTree::rotateRight(ZNode *n){
    ZNode* pt = new ZNode();
    pt = n -> parent;
    ZNode* leftch = new ZNode();
    ZNode* rightch = new ZNode();
    leftch = n -> left;
    rightch = n -> right;
    leftch -> parent = pt;
    if(leftch -> right != NULL){
        leftch -> right -> parent = n;       
    }
    n -> left = leftch -> right;
    leftch -> right = n;
    n -> parent = leftch;
    if(pt != NULL){
        if(n == pt -> left)
            pt -> left = leftch;
        else if(n == pt -> right)
            pt -> right = leftch;
    }
    n = leftch;
    if(n -> parent == NULL){
        root = n;
    }
    return n;
}

ZNode* AVLTree::rotateLeft(ZNode *n){

    ZNode* pt = new ZNode();
    pt = n -> parent;
    ZNode* leftch = new ZNode();
    ZNode* rightch = new ZNode();
    leftch = n -> left;
    rightch = n -> right;
    rightch -> parent = pt;
    if(rightch -> left != NULL){
        rightch -> left -> parent = n;       
    }
    n -> right = rightch -> left;
    rightch -> left = n;
    n -> parent = rightch;
    if(pt != NULL){
        if(n == pt -> left)
            pt -> left = rightch;
        else if(n == pt -> right)
            pt -> right = rightch;
    }
    n = rightch;
    if(n -> parent == NULL){
        root = n;
    }
    return n;
}

void AVLTree::printIO(ZNode *root){
    if(root == NULL)
        return;
    else{
        printIO(root -> left);
        cout << *(root -> zip) << endl;
        printIO(root -> right);
    }
}
void AVLTree::PrintPre(ZNode *root){
    if(root == NULL)
        return;
    else{
        cout << *(root -> zip) << endl;
        PrintPre(root -> left);
        PrintPre(root -> right);
    }

}
void AVLTree::PrintPost(ZNode *root){
    if(root == NULL)
        return;
    else{
        PrintPost(root -> left);
        PrintPost(root -> right);
        cout << *(root -> zip) << endl;
    }
}

