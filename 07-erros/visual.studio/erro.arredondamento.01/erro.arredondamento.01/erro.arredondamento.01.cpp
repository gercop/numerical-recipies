// erro.arredondamento.01.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float x;

	double y;

	x = 1;
	y = x + 1e-11; //MENOR DE 1E-5 O ERRO DE ARREDONDAMENTO PODE SER VISUALIZADO

	printf ("TESTANDO O ERRO DE ARREDONDAMENTO \n \n");
	printf ("A SOMA EH: %10.15f \n \n", y);

	system("pause");

	return 0;
}

