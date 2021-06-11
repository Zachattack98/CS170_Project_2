#ifndef VALIDATOR_H_
#define VALIDATOR_H_

//#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "ValidTimer.h"
#include "Classifier.h"
#include "Dataset.h"
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

        //transfer all inputted features into feat_subset
        for(int i = 0; i < subset.size(); i++)
            feat_subset[i] = subset[i];

    //read all instance IDs
    vector<double> instance_ID;
    //read all ground_truth_labels
    vector<double> ground_truth_label;
        
    Dataset* parse = new Dataset();
    
    parse->RowsandColumns("large.txt");
    parse->Parser("large.txt");
    
    cout << parse->rows << endl;
    cout << parse->cols << endl;
    
    for(int i = 0; i < parse->rows; i++) 
        ground_truth_label.push_back(parse->data[i][0]);  

    for(int i = 0; i < parse->rows; i++) 
        for(int j = 1; j < parse->cols; j++) 
            instance_ID.push_back(parse->data[i][j]);
        
        ValidTimer t;
        correct_predict_cnt = 0;
        float test_instance_ID = 0;
        float train_instances = 0;

        //timer start
		printf("Starting validation...");
		t.start();
        for(int i = 0; i < instance_ID.size(); i++) {
            for(int j = 0; j < subset.size(); j++) {
                test_instance_ID = instance_ID[feat_subset[j]-1][j];
            }

            train_instances = test_instance_ID - feat_subset[i];

            Classifier* test = new Test(test_instance_ID);

            if(test.predicted_label[i] == ground_truth_label[i]) {
                correct_predict_cnt++;
            }
        }

        //timer stop
        t.stop();
		printf("Time taken for validation = %0d ms", t.getTime());

		accuracy_scr  = correct_predict_cnt / (test_instance_ID + train_instances);
		printf("Using features {%0d}, the accuracy is {%0f}", feat_subset, accuracy_scr);
		
        return accuracy_scr;
    }

};

#endif