// erro.arredondamento.02.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "math.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float A,x;

	float y;

	printf ("TESTANDO O ERRO DE ARREDONDAMENTO \n \n");

	x = 1;	
	for (int i=0;i<=10;i++){
	  
	  A = 1e-11;       //AMPLITUDE
	  x = i*0.1*3.14;  //PERTURBAÇÃO

	  y = 1.0 + A*sin(x); //MENOR DE 1E-5 O ERRO DE ARREDONDAMENTO PODE SER VISUALIZADO

	  printf ("A SOMA EH: %10.15f \n", y);
	}		

	printf ("\n \n");

	system("pause");

	return 0;
}

