// gauss.eliminacao.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "windows.h"
#include "conio.h"
#include "math.h"

#define N 3

void gauss                (float a[N][N], float b[N]);
void gaussPivotagemParcial(float a[N][N], float b[N]);
void gaussPivotagemTotal  (float A[N][N], float b[N]);
void substituicao         (float a[N][N], float b[N]);

void espera_tecla();
void imprimea(int x, float a[N][N]);
void imprimeb(int x, float b[N]);
void imprimer(int x, float b[N]);
void gotoxy(int x, int y);

int _tmain(int argc, _TCHAR* argv[]){
	
	gotoxy(0,0); printf("SISTEMA LINEAR ax | b:");
	//float A[N][N] = {{0.00000002,2},{2,2}};
	//float b[N]    = {5,6};
	
	float A[N][N] = {{3,2,4},{1,1,2},{4,3,-2}};
	float b[N]    = {1,2,3};

	//float A[N][N] = {{3,2,1,-1},{0,1,0,3},{0,-3,-5,7},{0,2,4,0}};
	//float b[N]    = {5,6,7,15};			

	imprimea(0,A);	
	imprimeb(0,b);
	espera_tecla();

	//gauss(A,b);	 
	gaussPivotagemParcial(A,b);
	//gaussPivotagemTotal(A,b);
	
	return 0;
}

void gauss(float A[N][N], float b[N]){
  
  int i,j,k;
  float m;  

  for (k = 0; k < N-1; k++)
    for (i = k+1; i <= N-1; i++){
      m = A[i][k]/A[k][k];      
	  A[i][k] = 0;
      for (j = k+1; j<=N-1; j++){
	    A[i][j] = A[i][j] - m*A[k][j];
      }
	  b[i] = b[i] - m*b[k];	   
    }
  
  gotoxy(2*N+1,0); printf("SISTEMA TRIDIAGONAL SUPERIOR Ax | b:");
  imprimea(2*N+1,A);
  imprimeb(2*N+1,b);
  espera_tecla();
  
  substituicao(A,b);
}

void gaussPivotagemParcial(float A[N][N], float b[N]){

  int i,j,l,k;
  float m,max,aux;

  /* aplicar algoritmo de eliminacao de Gauss com pivotagem parcial*/
  for (k = 0; k < N-1; k++){
    max = abs(A[k][k]); 
    l = k;
    /* procurar o maior da coluna onde esta o pivot */
    for (i = k+1; i < N; i++){
      if (abs(A[i][k]) > max){
	    max = abs(A[i][k]);
	    l = i;
      }
    }
    /* se o maior nao e o pivot... */
    if (l != k){
      /* troca a linha onde esta o pivot atual pela linha onde esta o novo pivot */      
      for (j = 0; j <= N-1; j++){
	    aux = A[k][j];
	    A[k][j] = A[l][j];
	    A[l][j] = aux;
      }
	  
	  aux = b[k];
	  b[k] = b[l];
	  b[l] = aux;
    }
  }

  gotoxy(0,0); printf("PIVOTAMENTO PARCIAL Ax | b" );
  imprimea(0,A);
  imprimeb(0,b);
  espera_tecla();
  
  gauss(A,b);  
}

void gaussPivotagemTotal(float A[N][N], float b[N]){

  int l,c,i,j,k;
  float max,aux,m;

  /* aplicar algoritmo de eliminacao de Gauss com pivotagem total*/
  for (k = 0; k < N-1; k++){
    max = abs(A[k][k]);
    l = c = k;
    for (i = k; i < N; i++){
      for (j = k; j < N; j++){
	    if (abs(A[i][j]) > max){
	      max = abs(A[i][j]);
	      l = i;
	      c = j;
	    }
      }
    }
    if (l != k){      
      for (j = 0; j <= N-1; j++){
	    aux = A[k][j];
        A[k][j] = A[l][j];
	    A[l][j] = aux;
      }

  	  aux = b[k];
	  b[k] = b[l];
	  b[l] = aux;

    }    

    if (c != k){      
      for (j = 0; j < N; j++){
	    aux = A[j][k];
	    A[j][k] = A[j][c];
	    A[j][c] = aux;	    
      }
    }
  }

  gotoxy(0,0); printf("PIVOTAMENTO TOTAL Ax | b" );
  imprimea(0,A);
  imprimeb(0,b);
  espera_tecla();

  gauss(A,b);  
}

void substituicao(float A[N][N], float b[N]){

  float x[N],s;

  x[N-1] = b[N-1]/A[N-1][N-1];      
  for (int k = N-2; k>=0; k--){
	s = 0;
    for (int j=k+1; j<=N-1; j++){      
	  s = s + A[k][j]*x[j];	    
    }
	x[k] = (b[k] - s) / A[k][k];
  }

  gotoxy(4*N+2,0); printf("RESOLUCAO Ax | b:");
  imprimer(4*N+2,x);
  espera_tecla();

}

void imprimea(int x, float A[N][N]){

  for (int i = 0; i<N; i++){
    for (int j = 0; j<N; j++){
      gotoxy(x+i+2,14*j); printf("%.2f", A[i][j]);
    }    
  }  
}

void imprimeb(int x, float b[N]){

  for (int i = 0; i < N; i++){    
      gotoxy(x+i+2,N*15); printf("| %.2f", b[i]);
        
  }  
}

void imprimer(int x, float b[N]){

  for (int i = 0; i < N; i++){    
	  gotoxy(x+i+2,N*15); printf("|");
	  gotoxy(x+i+2,N*13); printf("%.2f ", b[i]);
        
  }  
}

void gotoxy(int x, int y){

  HANDLE stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD position;
  position.X = y;
  position.Y = x;
  SetConsoleCursorPosition(stdoutHandle, position);
}

void espera_tecla(){
  _getch();
}




