#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define f2

double analitico(double L, double Lo);

double f(double x) 
{
  #ifdef f1
    return 2.0*x;
  #else
    return pow(x,2);
  #endif
}

void entrada(double *Lo_local, double *L_local, int *n_local) 
{  
  printf("\nEntre com o inicio do dominio computacional: ");
  scanf("%lf",&(*Lo_local));
  printf("Entre com o final do dominio computacional: ");
  scanf("%lf",&(*L_local));
  printf("Entre com a quantidade de pontos: " );
  scanf("%d",&(*n_local));
}

void processamento(double Lo, double L, int n, double *integral_local)
{
  int i;
  double dx,x;

  *integral_local = 0.0;
  dx = (L-Lo)/n;

  for (i=0;i<n;i++) 
  {      
    x = Lo+i*dx;
    *integral_local += f(x)*dx;
  }  
}

void saida(double Lo_local, double L_local, double integral_local)
{
  
  double analitico_local = analitico(L_local,Lo_local);
  double erro_local      = analitico_local-integral_local;

  printf("Integral Numerica.: %15.10lf\n",  integral_local );
  printf("Integral Analitica: %15.10lf\n",  analitico_local);
  printf("Erro Numerico.....: %15.10lf\n\n",erro_local     );
}

double analitico(double L, double Lo)
{
  #ifdef f1
    return pow(L,2) - pow(Lo,2);  
  #else
    return pow(L,3)/3.0 - pow(Lo,3)/3.0;
  #endif
}

int main(void) 
{
  int n; 
  double integral=0.0,L,Lo;  
  char ch;

  do {
    entrada(&Lo,&L,&n);
    processamento(Lo,L,n,&integral);  
    saida(Lo,L,integral);
    
    printf("Deseja realizar outra integral <S/N>?");
    scanf("%s",&ch);

  } while (toupper(ch) == 'S');

  return 0;
}
