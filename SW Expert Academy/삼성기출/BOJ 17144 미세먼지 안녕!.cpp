#include <iostream>

using namespace std;

int cnt, R, C, T, robot[2], dir[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}}, room[51][51];

void spread() {
  int diff[51][51] = {0};
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      for(int k=0; k<4; k++) {
        int nx = i + dir[k][0], ny = j + dir[k][1], d = room[i][j]/5;
        if(nx < 0 || nx >= R || ny < 0 || ny >= C || room[nx][ny] == -1) continue;
        diff[i][j] -= d;
        diff[nx][ny] += d;
      }
    }
  }
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      room[i][j] += diff[i][j];
    }
  }
}

void upper() {
  int h = robot[0];
  for(int i=h-2; i>=0; i--) {
    room[i+1][0] = room[i][0];
  }
  for(int i=1; i<C; i++) {
    room[0][i-1] = room[0][i];
  }
  for(int i=1; i<=h; i++) {
    room[i-1][C-1] = room[i][C-1];
  }
  for(int i=C-2; i>0; i--) {
    room[h][i+1] = room[h][i];
  }
  room[h][1] = 0;
}

void lower() {
  int h = robot[1];
  for(int i=h+2; i<R; i++) {
    room[i-1][0] = room[i][0];
  }
  for(int i=1; i<C; i++) {
    room[R-1][i-1] = room[R-1][i];
  }
  for(int i=R-2; i>=h; i--) {
    room[i+1][C-1] = room[i][C-1];
  }
  for(int i=C-2; i>0; i--) {
    room[h][i+1] = room[h][i];
  }
  room[h][1] = 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>R>>C>>T;
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      cin>>room[i][j];
      if(room[i][j] == -1) robot[cnt++] = i;
    }
  }
  while(T--) {
    spread();
    upper();
    lower();
  }
  cnt = 0;
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      if(room[i][j] != -1) cnt += room[i][j];
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
