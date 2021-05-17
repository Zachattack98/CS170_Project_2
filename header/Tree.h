#ifndef TREE_H_
#define TREE_H_

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

//creating a Depth-First Search Tree containing all possible states until the goal state is reached
typedef pair<double, Node*> node_pair;


class Tree {
  public:
    Node* root;
    int expanded = 0;
    priority_queue<node_pair, vector<node_pair>, greater<node_pair>> frontier;
    stack<Node*> explored;
    vector<Node*> explore;

    int totalExpand;     //total number of nodes expanded

    //initialize the tree
    Tree(Node* input_root) {
        if (input_root == NULL)
            return;
        this->root = input_root;
        root->cost = 0;
        frontier.push(make_pair(0, root));
    }

};

#endif
