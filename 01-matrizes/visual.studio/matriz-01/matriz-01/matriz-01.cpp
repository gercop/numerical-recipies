// matriz-01.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"

using namespace std;

void display(int num[10])
{
  int i;
  for (i=0; i<10; i++)
    cout << num[i] << endl;  
  system("pause");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t[10],i;
	for (i=0; i<10; i++) 
		t[i] = i*i;  
	display(t);    

	return 0;
}

