#ifndef TREE_H_
#define TREE_H_

#include <bits/stdc++.h>
#include "Node.h"
#define N 3

using namespace std;

//creating a Depth-First Search Tree containing all possible states until the goal state is reached

class Tree {
  public:
    Node* root;
    stack<Node*> frontier;

    //initialize the tree
    Tree(Node* input_root) {
        if (input_root == NULL)
            return;
        this->root = input_root;
        frontier.push(this->root);
    }
};

#endif
