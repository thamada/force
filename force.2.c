#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Particle {
  double m;          // mass
  double rx, ry, rz; // position
  double ax, ay, az; // acceleration
};

void force(struct Particle pj[],
           struct Particle pi[],
           double eps2,
           int ni,
           int nj)
{
  int i, j;
  double dx, dy, dz;

  // 加速度を初期化
  for (i = 0; i < ni; i++) {
    pi[i].ax = 0.0;
    pi[i].ay = 0.0;
    pi[i].az = 0.0;
  }

  // 重力相互作用の計算
  for (i = 0; i < ni; i++) {
    for (j = 0; j < nj; j++) {
      double r2, r3;

      // 位置ベクトルの差を計算
      dx = pj[j].rx - pi[i].rx;
      dy = pj[j].ry - pi[i].ry;
      dz = pj[j].rz - pi[i].rz;

      // 距離の二乗を計算
      r2 = dx * dx + dy * dy + dz * dz + eps2;
      r3 = sqrt(r2) * r2;

      // 加速度の更新
      pi[i].ax += pj[j].m * dx / r3;
      pi[i].ay += pj[j].m * dy / r3;
      pi[i].az += pj[j].m * dz / r3;
    }
  }
}

int main() {
  // サンプル粒子データの初期化
  struct Particle pj[2] = {
    {1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {2.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0}
  };
  struct Particle pi[1] = {
    {1.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0}
  };

  double eps2 = 0.01;

  // 力を計算
  force(pj, pi, eps2, 1, 2);

  // 結果の出力
  printf("Acceleration of particle_i: (%f, %f, %f)\n", pi[0].ax, pi[0].ay, pi[0].az);

  return 0;
}
