#ifndef TREE_H_
#define TREE_H_

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

class Tree {
  public:
    Node* root;
    int expanded = 0;

    //initialize the tree
    Tree(Node* input_root) {
        if (input_root == NULL)
            return;
        this->root = input_root;
    }

};

#endif
