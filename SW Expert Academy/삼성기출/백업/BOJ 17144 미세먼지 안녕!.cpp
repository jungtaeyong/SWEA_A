#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct _dir{
  int x, y;
} Dir;

typedef struct _spread {
  int x, y, val;
} Spread;

int R,C;
int dust[52][52];
vector<Dir> cleaner;
Dir stream[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
queue<Spread> s;

void bfs(){
  for(int i=1; i<=R; i++) {
    for(int j=1; j<=C; j++) {
      if(dust[i][j] > 0) {
        int cnt = 0;
        for(int k=0; k<4; k++) {
          int nx = i + stream[k].x, ny = j + stream[k].y;
          if(nx < 1 || nx > R || ny < 1 || ny > C || dust[nx][ny] == -1) continue;
          Spread sPoint = {nx, ny, dust[i][j]/ 5};
          s.push(sPoint);
          cnt ++;
        }
        dust[i][j] -= cnt * (dust[i][j] / 5);
      }
    }
  }
  while(!s.empty()) {
    int x = s.front().x, y = s.front().y, val = s.front().val;
    s.pop();
    dust[x][y] += val;
  }
  for(int r=cleaner[0].x-1; r>0; r--) {
    if(dust[r+1][1] == -1) continue;
    dust[r+1][1] = dust[r][1];
  }
  for(int c=2; c<=C; c++) {
    dust[1][c-1] = dust[1][c];
  }
  for(int r=2; r<=cleaner[0].x; r++) {
    dust[r-1][C] = dust[r][C];
  }
  for(int c=C-1; c>1; c--) {
    dust[cleaner[0].x][c+1] = dust[cleaner[0].x][c];
  }
  dust[cleaner[0].x][2] = 0;
  for(int r=cleaner[1].x+1; r<=R; r++) {
    if(dust[r-1][1] == -1) continue;
    dust[r-1][1] = dust[r][1];
  }
  for(int c=2; c<=C; c++) {
    dust[R][c-1] = dust[R][c];
  }
  for(int r=R-1; r>=cleaner[1].x; r--) {
    dust[r+1][C] = dust[r][C];
  }
  for(int c=C-1; c>=2; c--) {
    dust[cleaner[1].x][c+1] = dust[cleaner[1].x][c];
  }
  dust[cleaner[1].x][2] = 0;
}

int main(){
  int T, accum = 0;
  cin>>R>>C>>T;
  for(int i=1; i<=R; i++) {
    for(int j=1; j<=C; j++) {
      cin>>dust[i][j];
      if(dust[i][j] == -1) {
        Dir cPoint = {i, j};
        cleaner.push_back(cPoint);
      }
    }
  }
  for(int i=0; i<T; i++) {
    bfs();
  }
  for(int i=1; i<=R; i++) {
    for(int j=1; j<=C; j++) {
      if(dust[i][j] > 0) accum += dust[i][j];
    }
  }
  cout<<accum<<"\n";
  return 0;
}
