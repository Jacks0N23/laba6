#include <iostream>
#include <c++/fstream>
#include <c++/iomanip>
#include "helper.h"


/**
 * 11. ���� ������� A �� N ����� (N>2) � M ��������. ���� ����� ���� ������ ����� ������� �
������ ����� ��������� ���� ��������� �� �����, �������� ������� �, �������� � ���������
������ ������ �������� �������� �1, �2, ..., �M.
 */

using namespace std;

int main() {


    int n, m, sum1, sum2;

    cout << "Hello, Maaaan!" << endl;

    char in[80];
    cout << "Enter input file name " << endl;
    gets(in);
    ifstream input_file(in);

    char out[80];
    cout << "Enter output file name " << endl;
    gets(out);
    ofstream output_file(out);


    input_file >> n;
    if (n < 2) {
        cout << "NUMBERS OF LINES MUST BE > 2" << endl;
        exit(1);
    }

    input_file >> m;
    output_file << n << "  numbers of lines" << endl;
    output_file << m << "  numbers of colomns" << endl;


    int **A = new int *[n];
    for(int k=0; k<n; k++)
    {
        A[k] = new int[m];
    }

sum1=sum2=0;
InAndSum(sum1,sum2,n,m, A, input_file);
InputMatrix(n,m, A, output_file);
output_file << "\n Summs: " << setw(5) << sum1 <<"\n"<< setw(5) << sum2 << endl;
check(sum1,sum2,n,m, A,input_file,output_file);

    input_file.close();
    output_file.close();

    for (int k = 0; k < n; k++) {
        delete[] A[k];
    }
    delete[] A;
return 0;

};