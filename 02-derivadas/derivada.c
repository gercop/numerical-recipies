#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#include "geral.h"

double funcao(double x); 
double analitico(double x);

int main(){ 

  long int i,n=32000,nshow=16;
  double Lo=-1.0f,L=1.0f,x,dx,der[n+1];

  
  dx = (double) (L-Lo)/n;

  FILE *file = fopen("derivada.txt","w");
  limpa();
  printf("PROCESSANDO O METODO - dx = %5.2f",dx);
  for (i=0; i<=n; i++) {      
    x = Lo+i*dx;
    der[i] = (funcao(x+dx)-funcao(x))/dx;    
  }

  for (i=0;i<=n; i= i + n/nshow) {
    x = Lo+i*dx;
    printf("x=%7.4f; f(x)=%7.4f; f'n(x)=%7.4f; f'e(x)=%7.4f; e=%10.9f \n",x,funcao(x),der[i],analitico(x),analitico(x)-der[i]);   
    fprintf(file,"%7.4f %7.4f %7.4f %7.4f %10.9f\n",x,funcao(x),der[i],analitico(x),analitico(x)-der[i]);
  }

  fclose(file);

  return 0;
}

double funcao(double x){  
  return pow(x,3)-2.0*x+5.0;
}

double analitico(double x) {
  return 3.0*pow(x,2)-2.0;
}


