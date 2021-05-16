#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
#include <cstdlib.h>  //random
using namespace std;

//use struct as its members are public by default
class Node {
    public:
        float accuracy; //data; accuracy represents the percentage of the evaluation
        float P_level;  //significance level; used to find all features unneccsary ( > P_level)
        Node* left_child, right_child;
        Node* parent = nullptr;

        // val is the value that has to be added to the data part
        Node() {
            int val;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << "Insert value for row " << i << " and column " << j << ":" << endl;
                    cin >> val;
                    data[i][j] = val;
                }
            }
        }

        //f is the number of features used in the search
        Node(int f){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    data[i][j] = f;
                }
            }

            // Left and right child are empty at the start
            left_child = NULL;
            right_child = NULL;
        }

};

#endif
