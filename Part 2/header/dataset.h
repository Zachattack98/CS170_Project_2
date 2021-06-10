#ifndef CS170_PROJECT_2_DATASET_H
#define CS170_PROJECT_2_DATASET_H

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Dataset
{
public:
    int data_size;

    Dataset() {
        data_size = 0;
    }

    void Parser(string filename) {
        string line, item;
        int i = 0, rows = 0, cols = 0;
        double x;
        string text_file_name = "../Part2/" + filename;
        
        //open file to determine number of columns and rows
        ifstream file;
        file.open(text_file_name);

        while (getline(file, line)) {
            rows++;
            if ( rows == 1 ) { //only need to know the number of columns by looking at a single row
              stringstream ss( line );      // Set up a stream from this line
              while ( ss >> item ) 
                cols++;  // Each item delineated by spaces adds one to cols
            }
        }
        file.close();
        
        
        double* data[rows][cols];
        
        //open file a second time to display the data
        ifstream file2;
        file2.open(text_file_name);
        
        
        while (!file2.eof()) {
            for (int j = 0; j < cols; j++) {
                file2 >> x;
                //cout << x << " ";
                data[i][j] = &x;
            }
            cout << endl;
            i++;
        }
        data_size = i;  //i is the same as rows
        
        file2.close();
        
};
#endif //CS170_PROJECT_2_DATASET_H
