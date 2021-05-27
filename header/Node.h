#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
#include <vector>
#include <ctime>
#include <time.h>

using namespace std;

class Node {
    public:
        Node* parent;
        vector<Node*> children;
        vector<char> curr_features;
        float accuracy, be_accuracy;

        Node() {
             parent = nullptr;
             accuracy = set_FS_Accuracy();
             //be_accuracy = set_BE_Accuracy();
        }

        Node(Node* node) {
            parent = node;
            accuracy = set_FS_Accuracy();
            //be_accuracy = set_BE_Accuracy();
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

        //accuracies in first selection
        float set_FS_Accuracy() {
            return rand()%100 + 1;
        }

        //accuracies in backward elimination
        /*float set_BE_Accuracy() {
            srand((unsigned int)time(NULL));
            return ((float)rand() / (float)(RAND_MAX)) * 100.0;
        }*/
        
        void printFeats() {
            if (curr_features.empty()) {
                cout << "{ }";
                return;
            }
            cout << "{";
            for (int i = 0; i < curr_features.size(); i++) {
                if (i < curr_features.size() - 1)
                    cout << curr_features.at(i) << ", ";
                else
                    cout << curr_features.at(i) << "}";
            }
        }
};

#endif
