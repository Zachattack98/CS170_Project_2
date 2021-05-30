#ifndef VALIDATOR_H_
#define VALIDATOR_H_

//#include <bits/stdc++.h>
#include <vector>
//#include <ctime>
//#include <time.h>
#include "Classifier.h"

using namespace std;

class Validator {
    public:
        vector<int> feat_subset; //subset containing all features currently working with
        float accuracy_scr; //total accuracy score using feature from feat_subset


    int leave_one_out_validation (vector<int> subset) {
        int correct_predict_cnt;    //keep track of all correct predictions

        //transfer all inputted features into feat_subset
        for(int i = 0; i < subset.size(); i++)
            feat_subset[i] = subset[i];

        //read all instance_IDs
        vector<int> instance_ID;

        //read all ground_truth_labels
        vector<int> ground_truth_label;

        correct_predict_cnt = 0;

        for(int i = 0; i < instance_ID.size(); i++) {
            //test_instance_ID = instance_ID;
            //train_instances = all other instances excluding test_instance
            //call Classifier.Test() and pass this test_instance_ID to it. It returns predicted_label

            /*if(predicted_label[i] == ground_truth_label[i]) {
                correct_predict_cnt++;
            }*/
        }

        //accuracy_scr = correct_predict_cnt / total number of instances;

		return accuracy_scr;
    }

};

#endif