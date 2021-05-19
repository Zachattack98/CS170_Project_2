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
        float accuracy;

        Node() {
             children.pop_back();
        }

        Node(Node* node) {
            parent = node;
        }

        void addFeature(char c) {
            for (int i = 0; i < parent->curr_features.size(); i++) {
                curr_features.push_back(parent->curr_features.at(i));
            }
            curr_features.push_back(c);
        }

        void removeFeature(char c) {
            for (int i = 0; i < parent->curr_features.size(); i++) {
                if (parent->curr_features.at(i) != c)
                    curr_features.push_back(parent->curr_features.at(i));
            }
        }
};

#endif
