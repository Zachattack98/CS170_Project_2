#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
//#include <cstdlib.h>  //random
#include <ctime>
using namespace std;

//use struct as its members are public by default
class Node {
    public:
        float accuracy[100][100]; //data; accuracy represents the percentage of the evaluation
        //int features;
        int cost;
        Node* parent = nullptr;
        Node* left_child = nullptr;
        Node* right_child = nullptr;

        Node() {}

        // get the accuracy as the data found at each node
        //f is the number of features used in the search
        Node(int f){
            srand((unsigned int)time(NULL));

            //there will always be 2^f combinations
            for (int i = 0; i < f; i++) {
                for (int j = 0; j < f; j++) {
                    //generate a random evaluation (or percentage) within each node
                    accuracy[i][j] = ((float)rand()/(float)(RAND_MAX)) * 100.0;
                }
            }

            // Left and right child are empty at the start
            left_child = NULL;
            right_child = NULL;
        }

};

#endif
