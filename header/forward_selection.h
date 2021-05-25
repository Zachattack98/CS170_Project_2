#ifndef CS170_PROJECT_2_FORWARD_SELECTION_H
#define CS170_PROJECT_2_FORWARD_SELECTION_H

#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"

using namespace std;

//Greedy Forward Selection
class Select {
public:
    Node* root;
    vector<char> feats = {'a', 'b', 'c', 'd'};
    int features = 4;
    int selected; //total number of features that were selected

    Select(int feats) {
        root = new Node();
        features=feats;
        features = 4;
    }

    void forwardSelect() {
        Tree *tree = new Tree(root);
        for (int i = 0; i < 4; i++) {
            expandChildren(tree);
            if (!pickChild(tree)) {
                cout << "Finished search!" << endl;
                return;
            }
        }
    }

    void expandChildren(Tree* tree) {
        int feature_size;
        vector<char> new_features;
        Node* currNode = tree->currNode;
        feature_size = tree->currNode->curr_features.size();


        if (feature_size < 4) {
            new_features = validFeatures(currNode, feature_size);
            for (int i = 0; i < 4 - feature_size; i++) {
                Node* newNode = new Node(tree->currNode);
                newNode->addFeature(new_features.at(i));
                currNode->children.push_back(newNode);
            }
            for (int i = 0; i < currNode->children.size(); i++) {
                cout << "Using feature(s) ";
                currNode->children.at(i)->printFeats();
                cout << " accuracy is " << currNode->children.at(i)->accuracy << endl;
            }
            cout << "\n";
        }
    }

    bool pickChild(Tree* tree) {
        bool child_chosen = false;
        Node* currNode = tree->currNode;
        Node* maxNode = tree->currNode;
        for (int i = 0; i < currNode->children.size(); i++) {
            if (maxNode->accuracy < tree->currNode->children.at(i)->accuracy) {
                maxNode = currNode->children.at(i);
                child_chosen = true;
            }
        }

        tree->currNode = maxNode;
        cout << "Feature set ";
        tree->currNode->printFeats();
        cout << " was the best, accuracy is " << tree->currNode->accuracy << endl;
        return child_chosen;
    }




    vector<char> validFeatures(Node* currNode, int feature_size) {
        vector<char> new_feature;
        vector<char> invalid_feats;
        bool invalid;

        if (feature_size == 0) {
            for (int i = 0; i < 4; i++)
                new_feature.push_back(feats.at(i));
        }

        else if (feature_size < 4) {
            for (int i = 0; i < feature_size; i++)
                invalid_feats.push_back(currNode->curr_features.at(i));
            for (int i = 0; i < 4; i++) {
                invalid = false;
                for (int j = 0; j < feature_size; j++) {
                    if (invalid_feats.at(j) == feats.at(i))
                        invalid = true;
                }
                if (!invalid)
                    new_feature.push_back(feats.at(i));
            }
        }
        return new_feature;
    }
};

#endif
