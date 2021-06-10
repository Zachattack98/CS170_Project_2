#ifndef VALIDATOR_H_
#define VALIDATOR_H_

//#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "ValidTimer.h"
#include "Classifier.h"

using namespace std;

class Validator {
    public:
        vector<int> feat_subset; //subset containing all features currently working with
        float accuracy_scr = 0.0; //total accuracy score using feature from feat_subset
        int num_lines = 0;  //number of rows with the given text file
        string line;
        int label;

    int leave_one_out_validation (vector<int> subset, string file_choice) {
        int correct_predict_cnt;    //keep track of all correct predictions
        ifstream myfile(file_choice);   //open file; read from the appropriate file
        
        //while(getline(myfile, line))    //while there is still lines to read 
            //++num_lines;

        //transfer all inputted features into feat_subset
        for(int i = 0; i < subset.size(); i++)
            feat_subset[i] = subset[i];

        //Read all instance IDs
        vector<vector<float>> instance_ID;
        //Read all ground truth labels
        vector<vector<int>> ground_truth_label;
        
        fstream myfile;
        myfile.open(file_choice);   //open file; read from the appropriate file
          
        string line;
        while(getline(myfile,line)) {
            instance_ID.push_back(vector<float>());
            ground_truth_label.push_back(vector<int>());
            
            //Break down the row to get only the values in the first column
            //and those remaining columns.
            //need two separate streams since we're reading from same file, else push backs in second while loop will be blank
            stringstream split1(line), split2(line);

            //since labels are whole numbers and ids are fractional, the terms will be separated automatically between both vectors
            float data_ID;
            int data_label;
            
            while(split1 >> data_ID) {
                instance_ID.back().push_back(data_ID);
            }
            while(split2 >> data_label) {
                ground_truth_label.back().push_back(data_label);
            }
        }
        myfile.close();
        
        ValidTimer t;
        correct_predict_cnt = 0;

        //timer start
		printf("Starting validation...");
		t.start();
        for(int i = 0; i < instance_ID.size(); i++) {
            vector<vector<float>> test_instance_ID = instance_ID;
            //train_instances = all other instances excluding test_instance
            //call Classifier.Test() and pass this test_instance_ID to it. It returns predicted_label

            /*if(predicted_label[i] == ground_truth_label[i]) {
                correct_predict_cnt++;
            }*/
        }

        //timer stop
        t.stop();
		printf("Time taken for validation = %0d ms", t.getTime());

		//accuracy_scr  = correct_predict_cnt / total number of instances
		printf("Using features {%0d}, the accuracy is {%0f}", feat_subset, accuracy_scr);
		
        return accuracy_scr;
    }

};

#endif
