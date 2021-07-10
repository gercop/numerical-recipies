#include<stdio.h>
#include<termios.h>

static struct termios old, new;

void limpa(void) {
  #ifdef LINUX
    system("clear");
    system("clear");
  #else
    system("cls");
  #endif  
}

//Quando você utiliza, em um mesmo programa C. a função scanf, junto com as funções gets ou getch, encontra alguns problemas com a aparente "não execução" de uma ou mais das chamadas destas funções. Dependendo do sistema operacional que voces está usando, haverá uma solução diferente para o problema. Para o caso do ambientes DOS, usando o TCLite ou o BorlandC, basta acrescentar, após o uso da scanf,  uma chamada à função fflush. Fonte: http://www.inf.pucrs.br/~pinho/LaproI/Fflush/CorrigeScanfGets.html
void flush_in()
{
  #ifdef LINUX
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
  #else
    fflush(stdin);
  #endif
} 

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) {
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
  return getch_(1);
}
