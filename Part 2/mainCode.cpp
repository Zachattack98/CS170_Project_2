//#include <bits/stdc++.h>
#include "Validator.h"
#include "Classifier.h"
#include <iostream>

using namespace std;

int main() {
    int nfeatures;

    cout << endl << "Enter the number of features used: " << endl;
    cin >> nfeatures;

    vector<int> feature_subset;

    for(int i = 0; i < nfeatures; i++) {
        cout << endl << "Input feature #" << i << ": ";
        cin >> feature_subset[i];

        cout << endl;
    }

    cout << "\n\nTotal accuracy score using subset {";
    for(int i = 0; i < nfeatures; i++) {
        cout << feature_subset[i];
        if(i != nfeatures-1)
            cout << ", ";
    }
    cout << "} is " << leave_one_out_validation(feature_subset) << "%" << endl << endl;

}