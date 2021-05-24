#ifndef NODE_H_
#define NODE_H_

//#include <bits/stdc++.h>
#include <vector>
#include <ctime>
using namespace std;

class Node {
public:
    Node* parent;
    vector<Node*> children;
    vector<char> curr_features;
    float accuracy;

    Node() {
        parent = nullptr;
    }

    Node(Node* node) {
        parent = node;

        srand((unsigned int)time(NULL));
        
        for (int i = 0; i < parent->curr_features.size(); i++) {
            //generate a random accuracy (or percentage) within each node
            accuracy = ((float)rand()/(float)(RAND_MAX)) * 100.0;
        }
    }

    void addFeature(char c) {
        for (int i = 0; i < parent->curr_features.size(); i++) {
            curr_features.push_back(parent->curr_features.at(i));

        Node(Node* node) {
            parent = node;
            
            srand((unsigned int)time(NULL));

            for (int i = 0; i < parent->curr_features.size(); i++) {
                    //generate a random accuracy (or percentage) within each node
                    accuracy[i] = ((float)rand()/(float)(RAND_MAX)) * 100.0;
            }
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