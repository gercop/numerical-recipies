#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Minhas Bibliotecas
#include "integral-c-geral.h"

#define ESC 27

//protótipos de procedimentos e funções
double analitico(double L, double Lo);

double f(double x) //passagem de parâmetro por cópia
{
  #ifdef f1
    return 2.0*x;
  #else
    return pow(x,2);
  #endif
}

//passagem de parâmetro por referência
void entrada(double *Lo_local, double *L_local, int *n_local) 
{
  printf("------------------------------------------------\n");
  printf("PROGRAMA DE INTEGRAÇÃO:\n");
  printf("------------------------------------------------\n");
  
  printf("\nEntre com o inicio do domínio computacional: ");
  scanf("%lf",Lo_local);
  printf("Entre com o final do domínio computacional : ");
  scanf("%lf",L_local);
  printf("Entre com a quantidade de pontos: " );
  scanf("%d",n_local);

  flush_in();   

  printf("\n");
  printf("------------------------------------------------\n");
  printf("MÉTODO DE INTEGRAÇÃO:\n");
  printf("------------------------------------------------\n");
  printf("\nDADOS: \n");
  printf("------------------------------------------------\n");
  printf("QUANTIDADE DE PONTOS  - N : %4.2e\n",(double)*n_local);  
  printf("DOMÍNIO COMPUTACIONAL - Lo: %lf \n",*L_local);
  printf("DOMÍNIO COMPUTACIONAL - L : %lf \n",*L_local);
  printf("PASSO DE INTEGRACAO   - DX: %lf \n",(*L_local-*Lo_local)/ *n_local);
  printf("------------------------------------------------\n\n");
}

double processo(double Lo, double L, int n)
{
  int i;
  double dx;
  double integral = 0.0;

  dx = (L-Lo)/n;

  for (i=0;i<n;i++)  
    integral += f(Lo+i*dx)*dx;

  return integral;
}

void saida(double Lo_local, double L_local, double integral_local)
{
  //Exemplo de declaração de variável com atribuição de valores (inicialização)
  double analitico_local = analitico(L_local,Lo_local);
  double erro_local      = analitico_local-integral_local;

  printf("RESULTADOS NUMÉRICOS \n");
  printf("------------------------------------------------\n");
  printf("Integral Numerica.: %15.10lf\n",integral_local );
  printf("Integral Analitica: %15.10lf\n",analitico_local);
  printf("Erro Numerico.....: %15.10lf\n",erro_local     );
  printf("------------------------------------------------\n\n");
}

double analitico(double L, double Lo)
{
  #ifdef f1
    return pow(L,2) - pow(Lo,2);  
  #else
    return pow(L,3)/3.0 - pow(Lo,3)/3.0;
  #endif
}

int main(void) //rotina principal na forma de função
{
  int n = 4; //inteiro longo - 4 bytes
  double integral = 0.0,L = 4.0,Lo = 0.0;  //real longo - 8 bytes
  char ch = {'N'}; 

  do {
    limpa();
    entrada(&Lo,&L,&n);
    saida  (Lo,L,processo(Lo,L,n));
    
    printf("Pressione ESC para sair do programa\n");
    ch = toupper( getch() );      
    
  } while (ch != ESC);

  return 0;
}
