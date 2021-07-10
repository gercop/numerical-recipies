#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double radianos2graus(double x){

  return 180.0/M_PI*x;
}

void main(void){

  int i,n=12;
  double theta,dtheta,r1,r2,r3,r4; 
  FILE *file;

  file = fopen("rosacea.txt","w");

  dtheta = 2.0*M_PI/n;

  for (i=0; i<=n; i++) {
    theta = i*dtheta;    
    r1 = 3.0*cos(2.0*theta);
    r2 = 3.0*sin(2.0*theta);
    r3 = 2.0*cos(2.0*theta);
    r4 = 2.0*sin(2.0*theta);

    fprintf (file, "%7.4f %7.4f %7.4f %7.4f %7.4f\n",radianos2graus(theta),r1,r2,r3,r4);
  }

  fclose(file);

}
