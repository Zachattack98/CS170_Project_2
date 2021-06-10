#ifndef CS170_PROJECT_2_DATASET_H
#define CS170_PROJECT_2_DATASET_H

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Dataset
{
public:
    double* data[100][11];
    int data_size;

    Dataset() {
        data_size = 0;
    }

    void Parser(string filename) {
        int i = 0;
        double x;
        string text_file_name = "../Part2/" + filename;
        ifstream file;
        file.open(text_file_name);

        while (file) {
            for (int j = 0; j < 11; j++) {
                file >> x;
//                cout << x << " ";
                data[i][j] = &x;
            }
            cout << endl;
            i++;
        }
        data_size = i;
    }


};
#endif //CS170_PROJECT_2_DATASET_H
