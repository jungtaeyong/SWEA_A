#include <iostream>
#include <vector>
#define U 1<<0
#define R 1<<1
#define D 1<<2
#define L 1<<3

using namespace std;

int N, M, ans = 64, office[8][8];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int,int> > cctv;
vector<int> step[5] = {
  {U, R, D, L},
  {U|D, R|L},
  {U|R, U|L, D|R, D|L},
  {U|R|L, D|R|L, R|U|D, L|U|D},
  {U|R|D|L}
};

void observe(int x, int y, int flag) {
  for(int k=0; k<4; k++) {
    if(flag & (1<<k)) {
      int dx = dir[k][0], dy = dir[k][1];
      int nx = x + dx, ny = y + dy;
      while(nx >= 0 && nx < N && ny >= 0 && ny < M && office[nx][ny] != 6) {
        if(office[nx][ny] == 0) office[nx][ny] = -1;
        nx += dx, ny += dy;
      }
    }
  }
}

void watch(int idx) {
  if(idx == cctv.size()) {
    int blank = 0;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(office[i][j] == 0) blank++;
      }
    }
    ans = min(ans, blank);
    return;
  }
  int cx = cctv[idx].first, cy = cctv[idx].second, temp[8][8];
  int type = office[cx][cy] - 1;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      temp[i][j] = office[i][j];
    }
  }
  for(int t=0; t<step[type].size(); t++) {
    observe(cx, cy, step[type][t]);
    watch(idx+1);
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        office[i][j] = temp[i][j];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin>>office[i][j];
      if(office[i][j] > 0 && office[i][j] < 6) cctv.push_back({i,j});
    }
  }
  watch(0);
  cout<<ans<<"\n";
  return 0;
}
