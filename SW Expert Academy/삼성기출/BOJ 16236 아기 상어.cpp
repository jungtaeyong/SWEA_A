#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct _fish{
  int x,y,d;
}Fish;

int cnt, N, t, bs = 2, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, space[21][21];
bool visited[21][21];
Fish pos, f;

bool isPossible() {
  memset(visited, 0, sizeof(visited));
  f = {-1, -1, -1};
  queue<Fish> q;
  q.push(pos);
  visited[pos.x][pos.y] = 1;
  while(!q.empty()) {
    Fish curr = q.front();
    q.pop();
    for(int k=0; k<4; k++) {
      int nx = curr.x + dir[k][0], ny = curr.y + dir[k][1], dist = curr.d;
      if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || space[nx][ny] > bs) continue;
      visited[nx][ny] = 1;
      q.push({nx, ny, dist+1});
      if(space[nx][ny] && space[nx][ny] < bs) {
        if(f.d == -1 || f.d > dist + 1) f = {nx, ny, dist+1};
        else if(f.d == dist + 1) {
          if(f.x > nx) f = {nx, ny, dist+1};
          else if(f.x == nx && f.y > ny) f = {nx, ny, dist+1};
        }
      }
    }
  }
  return f.d != -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>space[i][j];
      if(space[i][j] == 9) {
        pos.x = i, pos.y = j, pos.d = 0;
      }
    }
  }
  while(isPossible()) {
    space[pos.x][pos.y] = 0;
    pos = f;
    pos.d = 0;
    t += f.d;
    cnt++;
    if(cnt == bs) {
      bs++;
      cnt = 0;
    }
    space[f.x][f.y] = 9;
  }
  cout<<t<<"\n";
  return 0;
}
