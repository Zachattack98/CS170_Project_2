#ifndef CS170_PROJECT_2_DATASET_H
#define CS170_PROJECT_2_DATASET_H

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Dataset
{
public:
    double data[1000][41];
    int data_size, rows, cols;

    Dataset() {
        data_size = 0;
    }

    void RowsandColumns(string filename) {
        int i = 0, j = 0;
        string line, item;
        string text_file_name = filename;

        //open file to determine number of columns and rows
        ifstream file;
        file.open(text_file_name);

        while (getline( file, line )) {
            i++;
            if ( i == 1 ) { //only need to know the number of columns by looking at a single row
                stringstream ss( line );      // Set up a stream from this line
                while ( ss >> item )
                    j++;  // Each item delineated by spaces adds one to number of columns
            }
        }
        rows = i;
        cols = j;

        file.close();
    }

    void Parser(string filename) {
        int i = 0;
        double x;
        string text_file_name = filename;
        ifstream file;
        file.open(text_file_name);

        while (!file.eof()) {
            for (int j = 0; j < cols; j++) {
                file >> x;
//                cout << x << " ";
                data[i][j] = x;
            }
            cout << endl;
            i++;
        }
        data_size = i - 1;
        file.close();
    }


};
#endif //CS170_PROJECT_2_DATASET_H