#ifndef BACKWARD_ELIM_H
#define BACKWARD_ELIM_H

//#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"

using namespace std;

//Greedy Forward Selection
class Eliminate {
public:
    Node* root;
    vector<char> feats = { 'a', 'b', 'c', 'd' };
    float P_value = 0.05;  //step 1) significance level (5%); used to find all features unneccsary ( > P_level)
    int eliminated = 0; //total number of features that were eliminated
    //int accuracy_count = 0; //index that represents the accuracy chosen in the lit of randomly generated accuracies

    Eliminate() {
        root = new Node();
    }

    void backwardEliminate() {
        Tree* tree = new Tree(root);
        parentSet(tree);
        removeFeature(tree);

        for (int i = 0; i < 3; i++) {
            parentSet(tree);
            removeFeature(tree);
        }
        return;
    }

    void removeFeature(Tree* tree) {
        Node* currNode = tree->currNode;
        for (int i = 0; i < 4 - currNode->curr_features.size(); i++) {
            if (currNode->children.at(i)->curr_features.at(0) == 'b') {
                tree->currNode = currNode->children.at(i);
                cout << "feature(s) removed: ";
                eliminated++;
                for (int j = 0; j < tree->currNode->curr_features.size(); j++)
                    cout << tree->currNode->curr_features.at(j) << " ";

                Node* accuracyNode = new Node(currNode);

                cout << "\nAccuracy of new set: " << accuracyNode->accuracy << "%";
                cout << "\n\n";

                //accuracy_count++;

                return;
            }
        }
    }

    void parentSet(Tree* tree) {
        int feature_size;
        vector<char> new_features;
        Node* currNode = tree->currNode;
        cout << "size: " << 4 - tree->currNode->curr_features.size() << endl;
        feature_size = 4 - tree->currNode->curr_features.size();


        if (feature_size != 0) {
            new_features = validFeatures(currNode, feature_size);
            cout << "current parent node: ";
            for (int i = 0; i < feature_size; i++) {
                Node* newNode = new Node(tree->currNode);
                newNode->addFeature(new_features.at(i));
                cout << new_features.at(i) << " ";
                currNode->children.push_back(newNode);
            }
            cout << "\n";

            /*cout << "child node chosen: ";
            for (int i = 0; i < feature_size-1; i++) {
                Node* newNode = new Node(tree->currNode);
                newNode->addFeature(new_features.at(i));
                cout << new_features.at(i) << " ";
                currNode->children.push_back(newNode);
            }
            cout << "\n";*/
        }
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
