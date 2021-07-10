// jacobi.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "conio.h"

#define N 4

using namespace std;

//float A[N][N] = {{8,1,-1},{1,-7,2},{2,1,9}};
//float b[N]    = {8,-4,12};
//float x[N]    = {0,0,0};

float A[N][N] = {{5,2,1,1},{1,10,1,3},{1,3,13,7},{1,2,4,14}};
float b[N]    = {5,6,7,15};			
float x[N]    = {0,0,0,0};


int _tmain(int argc, _TCHAR* argv[])
{

    int intermax = 100000;
    float tol = 0.001;

	int i,j;
	float calc_erro,xant[N],soma;

	int k=0;
	float erro = 999999;
	while ( (k<intermax) && (erro>=tol) ) {
		erro = 0;
		for (i=0; i<N; i++) 
			xant[i] = x[i];		
		for (i=0; i<N; i++){
			soma = 0;
			for (j=0;j<N;j++) 
				if (j!=i) 
					soma = soma + A[i][j]*xant[j];				
			x[i] = (b[i] - soma) / A[i][i];
			calc_erro = x[i] - xant[i];
			if (calc_erro < 0)
				calc_erro = calc_erro * -1;
			if (calc_erro > erro)
				erro = calc_erro;
			printf("\nInteracao %d -> x[%d]:%.4f (erro: %.4f)", k, i, x[i], calc_erro);
		}
		k++;
	}
	if (erro < tol)
		for (i=0; i<N; i++)
			printf ("\nValor x[%d]: %.4f",i,x[i]);
	else
		printf ("\nNao houve convergencia em %d iteracoes", intermax);

	_getche();
	return 0;
}

