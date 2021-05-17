#ifndef BACKWARD_ELIM_H
#define BACKWARD_ELIM_H

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

//Greedy Bachward Elimination
class Eliminate {
  public:
    float P_value = 0.05;  //step 1) significance level (5%); used to find all features unneccsary ( > P_level)
  
    float Eliminate(Node* root, int features){
      Tree* tree = new Tree(root)
        
      //step 2) retrieve all values found at each node in the tree then push to vector to store them
      for (int i = 0; i < features; i++) {
        for (int j = 0; j < features; j++) {
          tree->explored.push_back(root->accuracy[i + j]);
        }
      }
      
      //step 3) check for the predictor/value of all nodes to see which is highest
      
      //step 4) if highest predictor is higher than P-value, then 
      //step 5) eliminate that feature from the stack/list and find next highest in step 3)
      
      //step 6) once highest predictor found is less than P-value, all remaining features return as valid
      
      
    }
  
};

#endif
