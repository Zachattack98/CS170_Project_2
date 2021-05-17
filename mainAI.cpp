//#include <bits/stdc++.h>
#include "Tree.h"
//#include "problem.h"
#include <iostream>

using namespace std;

int main() {

    cout << "Welcome to Khuaja Sham's and Zachary Hill's Feature Selection Algorithm." << endl;

    while(1) {
        Node *root;
        int Algorithm;
        int nfeatures;

        cout << endl << "Enter the number of features used in this algorithm: " << endl;
        cin >> nfeatures;

        cout << endl << "Now select the type of algorithm from the list below"
             << "------------------------------------------------------"
             << "1. Forward Selection\n2. Backward Elimination\n3. Our Special Algorithm (not ready yet)"
             << endl;
        cin >> Algorithm;

        //Problem problem;
        //problem.algorithmchoice = Algorithm;

        /*if (problem.GraphSearch(root)) {
            cout << "Solution Found!" << endl;
            cout << problem.expandN << " nodes expanded." << endl;
            cout << "The maximum number of nodes in the queue at any one time: " << problem.maxqueuesize << endl;
        } else {
            cout << "Solution Failed!" << endl;
            cout << problem.expandN << " nodes expanded." << endl;
            cout << "The maximum number of nodes in the queue at any one time: " << problem.maxqueuesize << endl;
        }*/

        cout << "Proceed? (Y/N):" << endl;
        char proceed;
        cin >> proceed;
        if (proceed != 'Y')
            exit(0);
    }

}
