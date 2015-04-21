#include <iostream>
#include <conio.h>
#include <c++/fstream>
#include <c++/iomanip>

/**
 * 11. Дана матрица A из N строк (N>2) и M столбцов. Если сумма двух первых строк матрицы А
меньше суммы элементов двух последних ее строк, изменить матрицу А, прибавив к элементам
каждой строки заданные элементы Х1, Х2, ..., ХM.
 */

using namespace std;

int main() {
    cout << "Hello, Maaaan!" << endl;

    char in[80];
    cout << "Enter input file name "<< endl;
    gets(in);
    ifstream input_file(in, ios::in);



    char out[80];
    cout << "Enter output file name "<< endl;
     gets(out);
    ofstream output_file(out, ios::out);


    fflush(stdin);
    fflush(stdout);


    int n, m,i ,j, sum1, sum2,dop;
    int *X = new int[dop];
    int *A[]= {new int[n], new int[m]};
    int *AN[]= {new int[n], new int[m]};
    ;

    input_file >> n;
    if(n<2)
    {
        cout << "NUMBERS OF LINES MUST BE > 2"<<endl;
       exit(1);
    }

    input_file >> m;
    output_file << n << "  numbers of lines" << endl;
    output_file << m<<"  numbers of colomns" << endl;
    fflush(stdin);
    fflush(stdout);

    while (!input_file.eof())
    {
       for(i=0; i<n; i++)
       {
           for(j=0; j<m; j++)
           {
               input_file >> A[i][j];
               if(i<3)
                   sum1+=A[i][j];
               if(i>n-2)
                   sum2+=A[i][j];
           }
       }
    }

    output_file << "\nInputed Matrix" << endl;
    for(i=0; i<n; i++)
    {
    output_file << endl;
        for(j=0; j<m; j++)
        {
        output_file << setw(5) << A[i][j];
        }
    }

    if(sum1<sum2)
    {
        cout << "Input values which need to sum" << endl;
        for(i=0; i<m; i++)
        {
            input_file >> X[i];
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
               A[i][j]+=X[i];
            }
        }

        output_file << "\nChanged Matrix " << endl;

        for(i=0; i<n; i++)
        {
            output_file << endl;
            for(j=0; j<m; j++)
            {
                output_file << setw(5) << A[i][j];
            }
        }

    }
    else
        output_file << "\nsum1 >sum2" << endl;


    input_file.close();
    output_file.close();
    delete[] X;
  delete[] A;
    return 0;

}