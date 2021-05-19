#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
//#include <cstdlib.h>  //random
#include <ctime>
using namespace std;

class Node {
    public:
        Node* parent;
        vector<Node*> children;
        vector<char> curr_features;
        float p_value;

        Node() {
             children.pop_back();
        }

        Node(Node* node) {
            parent = node;
        }

        void addFeatures(char c) {
            for (int i = 0; i < parent->curr_features.size(); i++) {
                curr_features.push_back(parent->curr_features.at(i));
            }
            curr_features.push_back(c);
        }

        void removeFeatures(char c) {
            for (int i = 0; i < parent->curr_features.size(); i++) {
                if (parent->curr_features.at(i) != c)
                    curr_features.push_back(parent->curr_features.at(i));
            }
        }
};

#endif
