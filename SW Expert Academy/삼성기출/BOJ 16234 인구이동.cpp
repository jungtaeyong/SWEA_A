#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

bool visited[51][51];
int y, accum, cnt, N, L, R, A[51][51], dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
queue<pii> q, chk;

bool movable() {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int k=0; k<4; k++) {
        int nx = i + dir[k][0], ny = j + dir[k][1];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        int diff = abs(A[i][j] - A[nx][ny]);
        if(diff >= L && diff <= R) return 1;
      }
    }
  }
  return 0;
}

void open() {
  while(!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for(int k=0; k<4; k++) {
      int nx = x + dir[k][0], ny = y + dir[k][1];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
      int diff = abs(A[x][y] - A[nx][ny]);
      if(diff >= L && diff <= R) {
        visited[nx][ny] = 1;
        accum += A[nx][ny];
        cnt++;
        q.push({nx,ny});
        chk.push({nx,ny});
      }
    }
  }
  accum /= cnt;
  while(!chk.empty()) {
    int x = chk.front().first, y = chk.front().second;
    chk.pop();
    A[x][y] = accum;
  }
}

void move() {
  memset(visited, 0, sizeof(visited));
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      accum = cnt = 0;
      if(!visited[i][j]) {
        accum += A[i][j];
        cnt++;
        visited[i][j] = 1;
        q.push({i,j});
        chk.push({i,j});
        open();
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>L>>R;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>A[i][j];
    }
  }
  while(movable()) {
    move();
    y++;
  }
  cout<<y<<"\n";
  return 0;
}
