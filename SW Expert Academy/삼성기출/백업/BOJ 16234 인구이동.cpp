#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

int N, L, R, cnt, nation[50][50], accum, unionCnt;
int dist[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[50][50];
queue<pair<int, int> > s, chk;

bool chkDist(){
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int k=0; k<4; k++) {
        int nx = i + dist[k][0], ny = j + dist[k][1];
        if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;
        int dif = abs(nation[i][j] - nation[nx][ny]);
        if(dif >= L && dif <=R) return true;
      }
    }
  }
  return false;
}

void makeUnion() {
  while(!s.empty()) {
    int curx = s.front().first, cury = s.front().second;
    s.pop();
    for(int k=0; k<4; k++) {
      int nx = curx + dist[k][0], ny = cury + dist[k][1];
      if(nx < 0 || nx >= N || ny < 0 || ny >=N || visited[nx][ny]) continue;
      int dif = abs(nation[curx][cury] - nation[nx][ny]);
      if(dif >= L && dif <=R) {
        accum += nation[nx][ny];
        unionCnt++;
        visited[nx][ny] = 1;
        s.push(make_pair(nx, ny));
        chk.push(make_pair(nx, ny));
      }
    }
  }
  int div = accum / unionCnt;
  while (!chk.empty()) {
    int x = chk.front().first, y = chk.front().second;
    chk.pop();
    nation[x][y] = div;
  }
}

void moveNation() {
  memset(visited, 0, sizeof(visited));
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      accum = 0, unionCnt = 0;
      if(!visited[i][j]) {
        accum += nation[i][j];
        unionCnt++;
        visited[i][j] = 1;
        s.push(make_pair(i, j));
        chk.push(make_pair(i,j));
        makeUnion();
      }
    }
  }
}

int main(){
  cin>>N>>L>>R;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>nation[i][j];
    }
  }
  
  while(chkDist()) {
    moveNation();
    cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}
