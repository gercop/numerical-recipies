// erro.truncamento.01.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "math.h"

using namespace std;

float fatorial(float n){

	float fat = 1;
	for (int i=2; i<=n; i++)
		fat *= i;
	return fat;
}

float elevado(float b, float n){
	return pow(b,n);
}

float serie(float x, int n){

	float sinal = -1;
	float soma = 0;
	
	soma = x;
	for (int i=1; i<=n-1; i++)
	{
		soma += sinal*pow(x,2*i+1)/fatorial(2*i+1);
		sinal *= -1;
	}

	return soma; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	double A,x,erro;

	double y_teorico, y_numerico;

	printf ("TESTANDO O ERRO DE ARREDONDAMENTO \n \n");

	x = 1;	
	for (int i=0;i<=10;i++){
	  
	  A = 1e-11;       //AMPLITUDE
	  x = i*0.1*3.14;  //PERTURBAÇÃO

	  y_teorico  = sin(x); //MENOR DE 1E-5 O ERRO DE ARREDONDAMENTO PODE SER VISUALIZADO
	  y_numerico = serie(x,3);

	  erro = y_teorico - y_numerico;

	  printf ("A SOMA EH: %10.15f %10.15f %10.15f\n", y_teorico, y_numerico, erro);
	}		

	printf ("\n \n");

	system("pause");

	return 0;
}

