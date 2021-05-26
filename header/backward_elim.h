#ifndef BACKWARD_ELIM_H
#define BACKWARD_ELIM_H

//#include <bits/stdc++.h>
#include "Node.h"
#include "Tree.h"

using namespace std;

//Greedy Backward Elimination
class Eliminate {
public:
    Node* root;
    vector<char> feats = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
    vector<char> new_features;
    int num_features;       //number of features used in the tree
    int high_node = 0;    //locate the node with the highest accuracy in the given group of children
    float max_acc = 0.0;  //highest overall accuracy
    
    int eliminated = 0; //total number of features that were eliminated
    float accuracy[91]; //array of all accuracies found during the greedy search
    float compare_acc[13]; //variable used to compare accuracy of each child and find/hold the highest in each group
    
    int acc_cnt2 = 0;                   //
    int compare_cnt2 = 0;               // counter variables
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;   //
        
    
    Eliminate(int feats) {
        root = new Node();
        num_features = feats;
    }

    void backwardEliminate() {
        Tree* tree = new Tree(root);
        
        srand((unsigned int)time(NULL));

        int nAcc = 0;   //number of total greedy accuracies
        int temp_f = num_features;
        
        //loop works as follows: cnt + (cnt-1) + (cnt-1-1) + (cnt-1-1-1)
        //if num_features = 4 -> 4 + 3 + 2 + 1 = 10 random accuracies
        for (int i = 0; i < num_features; i++) {
            nAcc += temp_f;
            temp_f--;
        }
        
        
        for (int i = 0; i < nAcc; i++) {
            accuracy[i] = ((float)rand() / (float)(RAND_MAX)) * 100.0;
        }

        parentSet(tree);
        removeFeature(tree);

        
        for (int i = 0; i < num_features-1; i++) {
            parentSet(tree);
            removeFeature(tree);
        }
        
        //find maximum overall accuracy and total features eliminated
        for (int i = 0; i < num_features; i++) {
            if (i == 0) {
                max_acc = compare_acc[0];
                eliminated = 1;
            }
            else if(max_acc < compare_acc[i]) {
                max_acc = compare_acc[i];
                eliminated = i + 1;
            }
        }
        
        cout << "\n\nFinished search!!! The best feature subset { ";
        for (int j = 0; j < eliminated; j++)
            cout << tree->currNode->curr_features.at(j) << " ";
        cout << "} had an accuracy of " << max_acc << "%" << endl;
        
        return;
    }

    void removeFeature(Tree* tree) {
        Node* currNode = tree->currNode;
        
        //generate a random accuracy (or percentage) within each node
        for (int i = 0; i < num_features - currNode->curr_features.size(); i++) {
            cout << "Accuracy for removing feature {" << new_features.at(i) << "} : " << accuracy[acc_cnt2] << "%";
            cout << "\n";
                    
            acc_cnt2++;
        }
        
        tree->currNode = currNode->children.at(high_node);
        cout << "feature(s) removed: ";
        for (int j = 0; j < tree->currNode->curr_features.size(); j++)
            cout << tree->currNode->curr_features.at(j) << " ";
        cout << "-> resulting in an accuracy of " << compare_acc[compare_cnt2] << "%";
        cout << "\n\n";

        compare_cnt2++;
        high_node = 0;
        
        return;
    }

    void parentSet(Tree* tree) {
        int feature_size;
        
        Node* currNode = tree->currNode;
        cout << "size: " << num_features - tree->currNode->curr_features.size() << endl;
        feature_size = num_features - tree->currNode->curr_features.size();

        
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
        }
        
        //acquire all values/accuracies for compare_acc
        for (int i = cnt1; i < (cnt1 + num_features - currNode->curr_features.size()); i++) {  
            if (i == 0)
                compare_acc[cnt3] = accuracy[0];    //this will only implement once
            if (compare_acc[cnt3] < accuracy[i]) {
                compare_acc[cnt3] = accuracy[i];    //assignment only the highest accuracy among each set of children     
                high_node = i - cnt1;
            }
                
            cnt2++;
        }
        cnt1 = cnt2;
        cnt3++;
    }

    vector<char> validFeatures(Node* currNode, int feature_size) {
        vector<char> new_feature;
        vector<char> invalid_feats;
        bool invalid;

        
        if (feature_size == num_features) {
            for (int i = 0; i < num_features; i++)
                new_feature.push_back(feats.at(i));
        }
        
        else if (feature_size < num_features) {
            
            for (int i = 0; i < (num_features - feature_size); i++) {
                invalid_feats.push_back(currNode->curr_features.at(i));
            }
            
            for (int i = 0; i < num_features; i++) {
                invalid = false;
                
                for (int j = 0; j < (num_features - feature_size); j++) {
                    //j++;
                    if (invalid_feats.at(j) == feats.at(i)) {
                        invalid = true;
                    }
                }
                
                if (!invalid) {
                    new_feature.push_back(feats.at(i));
                }
            }
        }
        return new_feature;
    }
};

#endif