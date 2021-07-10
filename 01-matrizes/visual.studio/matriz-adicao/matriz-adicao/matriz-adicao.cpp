// matriz-adicao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	 //Criei duas matrizes
    int A [2][2] = {
        {2,1},
        {0,2}
    };

    int B [2][2] = {
        {2,8},
        {4,2}
    };

    int soma[2][2];
   
    //varrer as duas matrizes somando
    for (int i=0; i <2; i++)
        for (int j=0; j<2; j++){       
            soma[i][j] = A[i][j] + B[i][j];
            cout << "i=" << i << " j=" << j << ":" << soma[i][j] << endl;
        }
    system("pause");
	return 0;
}

