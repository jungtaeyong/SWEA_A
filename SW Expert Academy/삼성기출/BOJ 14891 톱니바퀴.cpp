#include <cstdio>

using namespace std;

int K, n, d, turned[4], gear[4][8];

void clockwise(int idx) {
  int front = gear[idx][0];
  for(int i=7; i>0; i--) {
    gear[idx][(i+1)%8] = gear[idx][i];
  }
  gear[idx][1] = front;
}

void counterwise(int idx) {
  int front = gear[idx][0];
  for(int i=1; i<8; i++) {
    gear[idx][(i+8-1)%8] = gear[idx][i];
  }
  gear[idx][7] = front;
}

void turn(int idx, int dir) {
  if(idx < 0 || idx > 3 || turned[idx] != 0) return;
  int l = gear[idx][6], r = gear[idx][2];
  turned[idx] = dir;
  if(idx > 0) {
    if(l != gear[idx-1][2]) {
      turn(idx-1, -dir);
    }
  }
  if(idx < 3) {
    if(r != gear[idx+1][6]) {
      turn(idx+1, -dir);
    }
  }
}

int main() {
  int ans = 0, score[4];
  score[0] = 1;
  for(int i=1; i<4; i++) score[i] = score[i-1]*2;
  for(int i=0; i<4; i++) {
    for(int j=0; j<8; j++) {
      scanf("%1d", &gear[i][j]);
    }
  }
  scanf("%d", &K);
  for(int i=0; i<K; i++) {
    for(int i=0; i<4; i++) {
      turned[i] = 0;
    }
    scanf("%d %d", &n, &d);
    turn(n-1, d);
    for(int j=0; j<4; j++) {
      if(turned[j] > 0) clockwise(j);
      else if(turned[j] < 0) counterwise(j);
    }
  }
  
  for(int i=0; i<4; i++) {
    if(gear[i][0]) ans += score[i];
  }
  printf("%d\n", ans);
  return 0;
}
