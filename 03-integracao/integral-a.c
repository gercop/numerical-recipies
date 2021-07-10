#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double funcao(double x){  
  return x;
}

double analitico(double Lo, double L) {
  return L*L/2.0 - Lo*Lo/2.0;
}

void main(){

  long int i,n=4;
  double Lo=0.0,L=4.0,dx,integral_numerico=0.0,integral_exato=analitico(Lo,L),erro;

  dx = (double) (L-Lo)/n;

  printf("\nPROCESSANDO O MÉTODO - dx = %8.6f\n\n",dx);
  for (i=1; i<n; i=i+1) 
    integral_numerico += funcao(Lo+i*dx)*dx;      

  erro = integral_exato-integral_numerico;
  printf("O valor da integral é: %9.6lf\n"  ,integral_numerico);
  printf("O valor analítico é  : %9.6lf\n"  ,integral_exato   );
  printf("O valor do erro é    : %9.6lf\n\n",fabs(erro)       ); 
}
