#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_

//#include <bits/stdc++.h>
#include <vector>
#include <ctime>
#include <time.h>

class Classifier
{
	
	function Train(...)
	{
		
		//inputs: 1) train_instances : M vectors each of size n where n = no. of features per instance, M = no. of total instances
    int num_feats_instance;   //number of features per instance
    vector<num_feats_instance> tot_instances; //number of total instances
    
		//2) train_labels : a list or 1-d vector or array of length M where train_labels[i] = labels of ith instance
		int train_labels[tot_instances];
    
    //OR
		//inputs: 1) train_instance_IDs
		
		//outputs: None
				//NN classifier isn't a real ML classifier so there is no model for the Train method to build using (train_instances, train_labels) and return.
				//I am guessing that's why the professor said there is no output for this method in the part 2 google doc.

	}

	function Test(test_instance <or test_instance_ID>)
	{
		//inputs: 1) test_instance: this is either the n-dimensional vector representing your test instance or just the unique ID or index of your test instance.
		
    //output: 1) predicted_label: the predicted label for this test_datapoint using the nearest neighbor classifer.
    int predicted_label;
    
		//Step 1: Get n-dimensional the test instance (if only ID given as input)
		
    
    //Step 2: Compute its distance from all train instances (you will need to produce a M-1 x 3 table like {instance_ID, distance_from_test_instance, label} at this step)


		//Option 1: Maybe use Classifier.Train() to get the actual train_instances and train_labels by just passing Classifier.Train() the list of train_instance_IDs?
		//(Note train_instance_IDs = all_IDs - test_instance_ID)
		//Then compute the M-1 x 3 table right here?
		
    //Option 2: Maybe use Classifier.Train() to actually compute all the distances too and return this M-1 x 3 table? 
		//(Note: By return I technically dont mean return, it could be a global M-1 x 3 table that just gets updated at every iteration such that you dont pass too much data around.)
		//(This would also probably follow the professors logic of Classifier.Train() not having any output... I dont know...)
		
    //Option 3: You could just read the data file and do everything right here eliminating the need for a Classifier.Train()? Since, you know, we arent training anything. 
		//I dont know...ask the professor please.

		
    
    //Step 3: Sort that M-1 x 3 table by distance_from_test_instance (ascending)
		
    //Step 4: predicted_label = label of first training instance in the sorted table.

		return predicted_label
	}
	
}