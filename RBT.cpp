#include "RBT.h"
#include <iostream>
void RBT::leftRotate(RBTNode* &root, RBTNode* &node) { // left rotation for balance
    RBTNode* right = node->right;
    node->right = right->left;
    if (node->right != nullptr)
        node->right->parent = node;
    right->parent = node->parent;
    if(node->parent == nullptr)
        root = right;
    else if(node == node->parent->left)
        node->parent->left = right;
    else
        node->parent->right = right;
    right->left = node;
    node->parent = right;

}
void RBT::rightRotate(RBTNode* &root, RBTNode* &node) { // right rotation for balance
    RBTNode* left = node->left;
    node->left = left->right;
    if (node->left != nullptr)
        node->left->parent = node;
    left->parent = node->parent;
    if(node->parent == nullptr)
        root = left;
    else if(node == node->parent->right)
        node->parent->right = left;
    else
        node->parent->left = left;
    left->right = node;
    node->parent = left;

}
RBTNode* RBT::basicInsert(RBTNode* root, Species key) { // insert nodes into tree
    if (root == nullptr) {
        RBTNode* t = new RBTNode(key);
        return t;
    }
    if (key.GetName() > root->s.GetName()) {
        root->right = basicInsert(root->right, key);
        root->right->parent = root;
    }
    else {
        root->left = basicInsert(root->left, key);
        root->left->parent = root;
    }
    return root;

}
void RBT::fixTree(RBTNode* &newNode) { // code inspired by tree problem solving lecture
 if(newNode->parent == nullptr) {
     newNode->setRed(false);
     return;
 }
 if(!(newNode->parent->isRed())) {
     return;
 }
    RBTNode* parent = newNode->parent;
    RBTNode* grandparent = parent->parent;
    RBTNode* uncle;
 if(grandparent->left == parent)
     uncle = grandparent->right;
 else
     uncle = grandparent->left;
 if(uncle != nullptr && uncle->isRed()){
     parent->setRed(false);
     uncle->setRed(false);
     grandparent->setRed(true);
     fixTree(grandparent);
     return;
 }
 if (newNode == parent->right && parent == grandparent->left) {
     rightRotate(root, parent);
     newNode = parent;
     parent = newNode->parent;
 }
 else if (newNode == parent->left && parent == grandparent->right) {
     leftRotate(root, parent);
     newNode = parent;
     parent = newNode->parent;
 }
 parent->setRed(false);
 grandparent->setRed(true);
 if(newNode == parent->left)
     rightRotate(root, grandparent);
 else
     leftRotate(root, grandparent);
}
RBTNode* RBT::search(RBTNode* root, string key) { // find node based on species name
    if (root == nullptr || root->s.GetName() == key) {
        return root;
    }
    if (key > root->s.GetName())
        return search(root->right, key);
    else
        return search(root->left, key);
}
void RBT::InOrder(RBTNode* root) { // tree traversal
    if(root != nullptr) {
        InOrder(root->left);
        root->s.GetStatus();
        InOrder(root->right);
    }
}
RBTNode* RBT::GetRoot() {
    return root;
}
