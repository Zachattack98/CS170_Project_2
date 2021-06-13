//#include <bits/stdc++.h>
#include "Validator.h"
#include "Dataset.h"
#include "Classifier.h"
#include <iostream>
#include "Tree.h"
#include "forward_selection.h"

using namespace std;

int main() {

    cout << "Welcome to Khuaja Shams's and Zachary Hill's Feature Selection Algorithm." << endl;

    while(1) {
        int Algorithm;
        int nfeatures;

        cout << endl << "Enter the number of features used in this algorithm: " << endl;
        cin >> nfeatures;

        cout << endl << "Now select the type of algorithm from the list below"
             << "\n1. Forward Selection\n2. Backward Elimination\n3. Our Special Algorithm (not ready yet)"
             << endl;
        cin >> Algorithm;

        if(Algorithm == 1) {
            Select* forward_selection = new Select(nfeatures);
            forward_selection->forwardSelect();
        }

        cout << "Proceed? (Y/N):" << endl;
        char proceed;
        cin >> proceed;
        if (proceed != 'Y')
            exit(0);
    }

//    vector<int> feats;
//    feats.push_back(3);
//    feats.push_back(5);
//
//    Validator *validator = new Validator;
//    cout << "acc: " << validator->leave_one_out_validation(feats, "../Part3/small80.txt", 0);


}