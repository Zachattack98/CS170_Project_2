//#include <bits/stdc++.h>
#include "Tree.h"
//#include "problem.h"
#include <iostream>
#include "forward_selection.h"
#include "backward_elim.h"

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

        //Problem problem;
        //problem.algorithmchoice = Algorithm;
        if(Algorithm == 1) {
            Select* forward_selection = new Select(nfeatures);
            forward_selection->forwardSelect();
        }
        else if(Algorithm == 2) {
            Eliminate* backward_elimination = new Eliminate(nfeatures);
            backward_elimination->backwardEliminate();
        
            cout << "Total features eliminated: " << backward_elimination->eliminated << endl << endl;
        }
        
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