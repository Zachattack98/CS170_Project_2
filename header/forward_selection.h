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
    float P_value = 0.05;  //step 1) significance level (5%); used to find all features unneccsary ( > P_level)
    int selected; //total number of features that were selected

    Select() {
        root = new Node();
    }

    void forwardSelect(){
        Tree *tree = new Tree(root);
        expandChildren(tree);
        if (!pickChild(tree))
            return;
        for (int i = 0; i < 3; i++) {
            expandChildren(tree);
            if (!pickChild(tree))
                return;
        }
    }

    void expandChildren(Tree* tree) {
        int feature_size;
        vector<char> new_features;
        Node* currNode = tree->currNode;
        feature_size = 4 - tree->currNode->curr_features.size();


        if (feature_size != 0) {
            new_features = validFeatures(currNode, feature_size);
            cout << "features left: ";
            for (int i = 0; i < feature_size; i++) {
                Node* newNode = new Node(tree->currNode);
                newNode->addFeature(new_features.at(i));
                cout << new_features.at(i) << " ";
                currNode->children.push_back(newNode);
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
        cout << "Node chosen: ";
        tree->currNode = maxNode;
        for (int j = 0; j < tree->currNode->curr_features.size(); j++)
            cout << tree->currNode->curr_features.at(j) << " ";
        cout << ", Accuracy: " << tree->currNode->accuracy << endl;
        return child_chosen;
    }



    vector<char> validFeatures(Node* currNode, int feature_size) {
        vector<char> new_feature;
        vector<char> invalid_feats;
        if (feature_size == 4) {
            for (int i = 0; i < 4; i++)
                new_feature.push_back(feats.at(i));
        }
        else if (feature_size == 3) {
            invalid_feats.push_back(currNode->curr_features.at(0));
            for (int i = 0; i < 4; i++) {
                if (invalid_feats.at(0) != feats.at(i))
                    new_feature.push_back(feats.at(i));
            }
        }
        else if (feature_size == 2) {
            invalid_feats.push_back(currNode->curr_features.at(0));
            invalid_feats.push_back(currNode->curr_features.at(1));
            for (int i = 0; i < 4; i++) {
                if (invalid_feats.at(0) != feats.at(i) && invalid_feats.at(1) != feats.at(i))
                    new_feature.push_back(feats.at(i));
            }
        }
        else if (feature_size == 1) {
            invalid_feats.push_back(currNode->curr_features.at(0));
            invalid_feats.push_back(currNode->curr_features.at(1));
            invalid_feats.push_back(currNode->curr_features.at(2));
            for (int i = 0; i < 4; i++) {
                if (invalid_feats.at(0) != feats.at(i) && invalid_feats.at(1) != feats.at(i) && invalid_feats.at(2) != feats.at(i))
                    new_feature.push_back(feats.at(i));
            }
        }
        else {
            cout << "feature size: " << feature_size << endl;
        }
        return new_feature;
    }
};

#endif
