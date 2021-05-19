#ifndef BACKWARD_ELIM_H
#define BACKWARD_ELIM_H

#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

//Greedy Bachward Elimination
class Eliminate {
  public:
    int eliminated; //total number of features that were eliminated
    vector<feature> bw_features; //new subset of features; does not contain any removed
    char highest_accuracy_bw;
    
    void Eliminate(Node* root, char features, float accuracy){
      Tree* tree = new Tree(root)
        
      //provide random values to all avalable combinations
      for (int i = 0; i < features; i++) {
        for (int j = 0; j < features; j++) {
          if (i != 0 && j != 0)
            tree->explored.push_back(accuracy[i][j])
          //tree->explored.push_back(root->accuracy[i + j]);
        }
      }
      
      while(features != feature) {

        if(features > feature) {
          addFeatures(features);
        }

        else if(features < f_init) {
          removeFeatures(features);
        }

      }

      //begin going down the tree from root
      while(features) {
        int j = 0;
        
        //displaying accuracy of each subset
        for (int i = 0; i < features; i++) {
          cout << "\nFeature(s) " << feature(i) << " shows an accuracy value of " << tree->explored[0][i] << "%";
          
          //if you find a higher accuracy, make that node the new parent
          if(i != 0 && (tree->explored[0][i-1] < tree->explored[0][i])) {
            root->parent.at(i);

            //pop the last subset then include the new (highest) subset
            bw_features.pop();
            bw_features.push_back(root->children.at(i));
          }

        }

        features--; 
        j++;
      }
        
      eliminated = (int)features - int(bw_features);

      cout << "\n\nA total of " << eliminated << " features were eliminated! Leaving us with the following set: ";
    }
  
};
