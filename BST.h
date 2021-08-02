#pragma once
#include "Species.h"
struct Node {
    Species s;
    Node* left;
    Node* right;
    Node(Species species): s(species), left(nullptr),right(nullptr) {}
    Node(Species species, Node* l, Node* r): s(species), left(l), right(r) {}
};
class BST {
    Node* head;
public:
    Node* insert(Node* root, Species key);
    Node* search(Node* root, string name);
    void InOrder(Node* root);
};

