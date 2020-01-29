#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _horse {
  int x, y, d;
}Horse;

Horse h[11];
vector<int> chess[13][13];
int N, K, ret = 1, color[13][13];
const int dir[5][2] = {{0,0}, {0,1}, {0,-1}, {-1,0}, {1,0}};

bool turn() {
  for(int i=1; i<=K; i++) {
    int x = h[i].x, y = h[i].y, d = h[i].d;
    int nx = x + dir[d][0], ny = y + dir[d][1];
    if(nx < 1 || nx > N || ny < 1 || ny > N || color[nx][ny] == 2) {
      d % 2 ? d++ : d--;
      h[i].d = d;
      nx = x + dir[d][0], ny = y + dir[d][1];
      if(nx < 1 || nx > N || ny < 1 || ny > N || color[nx][ny] == 2) continue;
    }
    vector<int>::iterator it = find(chess[x][y].begin(), chess[x][y].end(), i);
    if(color[nx][ny] == 1) {
      reverse(it, chess[x][y].end());
    }
    for(vector<int>::iterator s = it; s != chess[x][y].end(); s++) {
      h[*s].x = nx, h[*s].y = ny;
      chess[nx][ny].push_back(*s);
    }
    chess[x][y].erase(it, chess[x][y].end());
    if(chess[nx][ny].size()>=4) return 1;
  }
  return 0;
}

int main(){
  cin>>N>>K;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>color[i][j];
    }
  }
  for(int i=1; i<=K; i++) {
    cin>>h[i].x>>h[i].y>>h[i].d;
    chess[h[i].x][h[i].y].push_back(i);
  }
  while(ret <= 1000 && !turn()) {
    ret++;
  }
  cout<<(ret > 1000 ? -1 : ret)<<"\n";
  return 0;
}
