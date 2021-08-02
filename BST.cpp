#include "BST.h"
#include <iostream>
Node* BST::insert(Node* root, Species key) { // insert node into tree
    if (root == nullptr) {
        Node* t = new Node(key);
        return t;
    }
    if (key.GetName() > root->s.GetName())
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    return root;
}
Node* BST::search(Node* root, string name) { // find node based on name
    if (root == nullptr || root->s.GetName() == name) {
        return root;
    }
    if (name > root->s.GetName())
        return search(root->right, name);
    else
        return search(root->left, name);
}
void BST::InOrder(Node* root) { // inorder traversal of tree
    if(root != nullptr) {
        InOrder(root->left);
        string name = root->s.GetStatus();
        InOrder(root->right);
    }
}