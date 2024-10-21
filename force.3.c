#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
    float w;
} float4;

float4 inter(float4 xj,  float4 xi,  float4 apot)
{
    float mj    = xj.w;        // Mass Mj
    float ieps2 = xi.w;        // epsilon^2
    float dx = xj.x - xi.x;    // Coordinates Xj - Xi
    float dy = xj.y - xi.y;    // Coordinates Yj - Yi
    float dz = xj.z - xi.z;    // Coordinates Zj - Zi
    float r2 = dx * dx + dy * dy + dz * dz + ieps2;
    float r1i = 1.0f / sqrt(r2);
    float r2i = r1i * r1i;
    float mr3i = mj * r2i * r1i;
    apot.x += dx * mr3i;       // Accel AXi
    apot.y += dy * mr3i;       // Accel AYi
    apot.z += dz * mr3i;       // Accel AZi
    return (apot);
}

void force(double xj[][3], double mj[], double xi[][3], double eps2, double a[][3], int ni, int nj)
{
    int i, j;
  
    for(int i=0; i<ni ;i++)
        for(int d=0; d<3; d++)
            a[i][d] = 0.0;

    for (i = 0; i < ni; i++) {
        float4 apot = {0.0f, 0.0f, 0.0f, 0.0f};
        float4 pi = { xi[i][0], xi[i][1], xi[i][2], eps2 };

        for (j = 0; j < nj; j++) {
            float4 pj = { xj[j][0], xj[j][1], xj[j][2], mj[j] };
            apot = inter(pj, pi, apot);
        }

        a[i][0] = apot.x;
        a[i][1] = apot.y;
        a[i][2] = apot.z;
    }
}
