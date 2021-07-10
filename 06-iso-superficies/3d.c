#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define imax 60
#define jmax 60
#define kmax 60

int main(){

  int i,j,k;
  float f,x,y,z,
        Lxo=-1.0*M_PI,Lyo=-1.0*M_PI,Lzo=-1.0*M_PI,
        Lx =+1.0*M_PI,Ly =+1.0*M_PI,Lz =+1.0*M_PI,
        dx=(Lx-Lxo)/(imax-1),dy=(Ly-Lyo)/jmax,dz=(Lz-Lzo)/kmax;

  printf("PROGRAMA PARA GERAR SUPERFÍCIES\n");
  FILE *file = fopen("3d.txt","w");

  fprintf(file,"VARIABLES= x,y,z,f\n");
  fprintf(file,"ZONE I=%d,J=%d,K=%d,F=POINT\n",imax,jmax,kmax);
  for (i=0;i<imax;i++)
   for (j=0;j<jmax;j++)
     for (k=0;k<kmax;k++)
     {
        x = Lxo+i*dx; y = Lyo+j*dy; z = Lzo+k*dz;
        f = sin(x)+sin(y)+sin(z);
        fprintf(file,"%5.2f %5.2f %5.2f %8.7f\n",x,y,z,f);
        
     }

   close(file);  
   printf("PROGRAMA ENCERRADO.\n");
}
