#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
//#include <cstdlib.h>  //random
#include <ctime>
using namespace std;

enum feature {A, B, C, D};

class Node {
    public:
        vector<Node*> parents;
        vector<Node*> children;
        vector<feature> curr_features;
        double p_value;

        Node() {
             children.pop_back();
        }

        Node(Node* parent) {
            parents.push_back(parent);
        }
};

#endif
