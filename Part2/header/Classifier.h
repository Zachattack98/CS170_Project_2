#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_

//#include <bits/stdc++.h>
#include <vector>
#include <ctime>
#include <time.h>
#include "Dataset.h"

class Classifier
{
public:
	Dataset* training_data;
	int feature_size;
	vector<int> feature_indexes;

	void Train(Dataset* data, int num_instances, vector<int> &features) {
	    training_data = data;
	    feature_size = features.size();
        feature_indexes = features;
		//outputs: None
				//NN classifier isn't a real ML classifier so there is no model for the Train method to build using (train_instances, train_labels) and return.
				//I am guessing that's why the professor said there is no output for this method in the part 2 google doc.

	}

	int Test(int testing_instance)
	{
	    int predicted_label;
	    double distance;
	    double data[1][feature_size + 1];

	    for (int i = 0; i < feature_size; i++)
            data[0][i] = training_data->data[testing_instance][feature_indexes.at(i)];
        for (int i = 0; i < training_data->data_size; i++) {
            if (i == testing_instance)
                continue;
            for (int j = 0; j < feature_size; j++)
                distance += pow(data[0][j] - training_data->data[i][feature_indexes.at(j)], 2);
            distance = sqrt(distance);
//            cout << training_data->data[i][0]<< ":" << distance << " ";
        }
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

		return predicted_label;
	}
	
};

#endif