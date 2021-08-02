#pragma once
#include "Species.h"
struct RBTNode {
    Species s;
    bool red;
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;
    RBTNode(Species species): s(species), red(true),left(nullptr),right(nullptr),parent(nullptr) {}
    RBTNode(Species species, RBTNode* l, RBTNode* r): s(species), red(true),left(l), right(r), parent(nullptr) {}
    bool isRed() {return red;}
    void flipColor() {
        if(isRed())
            red = false;
        else
            red = true;
    }
    void setRed(bool b) {
        red = b;
    }
};
class RBT {
    RBTNode* root;
    void leftRotate(RBTNode* &root, RBTNode* &node);
    void rightRotate(RBTNode* &root, RBTNode* &node);
public:
    RBTNode* search(RBTNode* root, string key);
    void fixTree(RBTNode* &newNode);
    RBTNode* basicInsert(RBTNode* root, Species key);
    void InOrder(RBTNode* root);
    RBTNode* GetRoot();




};

