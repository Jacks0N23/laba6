//
// Created by Alexandr on 23.04.2015.
//

#ifndef LABA6_HELPER_H
#define LABA6_HELPER_H

#endif //LABA6_HELPER_H

#include <iostream>
#include <c++/fstream>
#include <c++/iomanip>


using namespace std;



int  InAndSum(int sum1, int sum2, int n, int m, int **A, ifstream& input_file) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input_file >> A[i][j];
            if (i < 2)
                sum1 += A[i][j];
            if (i > n - 3)
                sum2 += A[i][j];
        }
    }
    return sum1,sum2;
}

void InputMatrix(int n, int m, int **A, ofstream& output_file )
{

    output_file << "\nInputed Matrix" << endl;
    for (int i = 0; i < n; i++) {
        output_file << endl;
        for (int j = 0; j < m; j++) {
            output_file << setw(5) << A[i][j];

        }
    }
}
    void check(int sum1, int sum2, int n, int m, int **A, ifstream& input_file, ofstream& output_file)
    {

        if (sum1 < sum2) {
            cout << "Input values which need to sum" << endl;

            int *X = new int[n];

            for (int i = 0; i < n; i++) {
                input_file >> X[i];
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    A[i][j] += X[i];
                }
            }

            output_file << "\nChanged Matrix " << endl;

            for (int i = 0; i < n; i++) {
                output_file << endl;
                for (int j = 0; j < m; j++) {
                    output_file << setw(5) << A[i][j];
                }
            }
            delete[] X;
        }
        else
            output_file << "\nsum1 >sum2" << endl;
    }





