#ifndef CS170_PROJECT_2_FORWARD_SELECTION_H
#define CS170_PROJECT_2_FORWARD_SELECTION_H

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

//Greedy Forward Selection
class Select {
public:
    float P_value = 0.05;  //step 1) significance level (5%); used to find all features unneccsary ( > P_level)
    int selected; //total number of features that were selected

    float Select(Node* root, int features){
        Tree* tree = new Tree(root)

        //step 2) retrieve all values found at each node in the tree then push to vector to store them
        for (int i = 0; i < features; i++) {
            for (int j = 0; j < features; j++) {
                tree->explored.push_back(root->accuracy[i + j]);
            }
        }

        //show accuracy after using each feature individually
        for (int i = 0; i < features; i++) {
            cout << "\nFeature " << i << " shows a predictor value of " << tree->explored << "%";
        }


        //step 3) check for the predictor/value of all nodes to see which is highest

        for (int j = 0; j < features; j++) {
            cout << "\n\nFeature " << j << " is currently the best predictor, " << tree->explored << "%" ;
        }


        //step 4) if highest predictor is higher than P-value, then
        //step 5) eliminate that feature from the stack/list and find next highest in step 3)

        //step 6) once highest predictor found is less than P-value, all remaining features return as valid

        cout << "\n\nA total of " << eliminated << " features were eliminated! Leaving us with the following set: ";

    }

};

#endif
