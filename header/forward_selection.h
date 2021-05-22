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
    vector<char> curr_features;
    float P_value = 0.05;  //step 1) significance level (5%); used to find all features unneccsary ( > P_level)
    int selected; //total number of features that were selected

    Select() {
        root = new Node();
    }

    void forwardSelect(){
        Tree* tree = new Tree(root);
        expandChildren(tree);
        pickChild(tree);
        cout << tree->currNode->curr_features.at(0) << endl;
    }

    void expandChildren(Tree* tree) {
        int feature_size;
        vector<char> new_features;
        Node* currNode = tree->currNode;
        cout << "size" << tree->currNode->curr_features.size() << endl;
        feature_size = 4 - curr_features.size();


        if (feature_size != 0) {
            new_features = validFeatures(currNode, feature_size);
            for (int i = 0; i < feature_size; i++) {
                Node* newNode = new Node(tree->currNode);
                newNode->addFeature(new_features.at(i));
//                cout << new_features.at(i) << " ";
                currNode->children.push_back(newNode);
            }
        }
    }

    void pickChild(Tree* tree) {
        Node* currNode = tree->currNode;
        for (int i = 0; i < 4 - currNode->curr_features.size(); i++) {
            if (currNode->children.at(i)->curr_features.at(0) == 'c') {
                tree->currNode = currNode->children.at(i);
                return;
            }
        }
    }

    //MESSY CODE, for now just want to see if it works. In future will have a for loop that checks if each feature is already in the feature set before adding new feature.

    vector<char> validFeatures(Node* currNode, int feature_size) {
        vector<char> new_feature;
        vector<char> invalid_feats;
        if (feature_size == 4) {
            new_feature.push_back('a');
            new_feature.push_back('b');
            new_feature.push_back('c');
            new_feature.push_back('d');
        }
        else if (feature_size == 3) {
            invalid_feats.push_back(currNode->curr_features.at(0));
            if (invalid_feats.at(0) != 'a')
                new_feature.push_back('a');
            if (invalid_feats.at(0) != 'b')
                new_feature.push_back('b');
            if (invalid_feats.at(0) != 'c')
                new_feature.push_back('c');
            if (invalid_feats.at(0) != 'd')
                new_feature.push_back('d');
        }
        else if (feature_size == 2) {
            invalid_feats.push_back(currNode->curr_features.at(0));
            invalid_feats.push_back(currNode->curr_features.at(1));
            if (invalid_feats.at(0) != 'a' && invalid_feats.at(1) != 'a')
                new_feature.push_back('a');
            if (invalid_feats.at(0) != 'b' && invalid_feats.at(1) != 'b')
                new_feature.push_back('b');
            if (invalid_feats.at(0) != 'c' && invalid_feats.at(1) != 'c')
                new_feature.push_back('c');
            if (invalid_feats.at(0) != 'd' && invalid_feats.at(1) != 'd')
                new_feature.push_back('d');
        }
        else if (feature_size == 1) {
            invalid_feats.push_back(currNode->curr_features.at(0));
            invalid_feats.push_back(currNode->curr_features.at(1));
            invalid_feats.push_back(currNode->curr_features.at(2));
            if (invalid_feats.at(0) != 'a' && invalid_feats.at(1) != 'a' && invalid_feats.at(2) != 'a')
                new_feature.push_back('a');
            if (invalid_feats.at(0) != 'b' && invalid_feats.at(1) != 'b' && invalid_feats.at(2) != 'b')
                new_feature.push_back('b');
            if (invalid_feats.at(0) != 'c' && invalid_feats.at(1) != 'c' && invalid_feats.at(2) != 'c')
                new_feature.push_back('c');
            if (invalid_feats.at(0) != 'd' && invalid_feats.at(1) != 'd' && invalid_feats.at(2) != 'd')
                new_feature.push_back('d');
        }
        else {
            cout << "feature size: " << feature_size << endl;
        }
        return new_feature;
    }
};

#endif
