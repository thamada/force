#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void force(double xj[][3],
           double m[],
           double xi[][3],
           double eps2,
           double a[][3],
           int ni,
           int nj)
{
  double dx[3];

  for(int i=0; i<ni ;i++)
    for(int d=0; d<3; d++)
      a[i][d] = 0.0;

  for(int i=0; i<ni; i++){
    for(int j=0; j<nj; j++){
      double r2,r3;
      r2 = eps2;
      for(int d=0; d<3; d++){
        dx[d] = xj[j][d] - xi[i][d];
        r2 += dx[d] * dx[d];
      }
      r3 = sqrt(r2) * r2;
      for(int d=0; d<3; d++){
        a[i][d] +=  m[j]*dx[d]/r3;
      }
    }
  }
}
