// matriz-multiplicacao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,k,qtde_La,qtde_Ca,qtde_Lb,qtde_Cb;
	float m[10][10];
	float m1[10][10];
	float maux[10][10];

	cout << "Digite a quantidade de linhas da matriz A" << endl;
	cin >> qtde_La;	
	cout << "Digite a quantidade de colunas da matriz A" << endl;
	cin >> qtde_Ca;	
	
	cout << "Digite a quantidade de linhas da matriz B" << endl;
	cin >> qtde_Lb;	
	cout << "Digite a quantidade de colunas da matriz B" << endl;
	cin >> qtde_Cb;

	if (qtde_Ca == qtde_Lb) //Condição de existência do produto
	{
		cout << endl << "Digite os elementos da matriz A" << endl << endl;
		for(i=0; i<qtde_La; i++){
			for(j=0; j<qtde_Ca; j++){
				cout << "elemento " << i+1 << "," << j+1 << ":";
				cin >> m[i][j];
			}
		}
	
		cout << endl << "Digite os elementos da matriz B" << endl << endl;	
		for(i=0; i<qtde_Lb; i++) {
			for(j=0; j<qtde_Cb; j++){
				cout << "elemento " << i+1 << "," << j+1  << ":";
				cin >> m1[i][j];
				maux[i][j]=0;
			}
		}

		for(i=0; i<qtde_La; i++){
			for(j=0; j<qtde_Cb; j++){
				for(k=0; k<qtde_La; k++){
					maux[i][j] = maux[i][j] + (m[i][k]*m1[k][j]);
				}
			}
		}

		cout << endl << "As matrizes multiplicadas geram a matriz abaixo" << endl;
	
		for(i=0; i<qtde_La; i++){
			cout << endl;
			for(j=0; j<qtde_Cb; j++){
				cout << maux[i][j] << " ";
			}
		}
		cout << endl << endl;
	} else
		cout << "Condição de existência do produto não Satisfeita!";

	_getch();
	return 0;
}

