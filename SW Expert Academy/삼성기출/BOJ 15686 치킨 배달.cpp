#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

typedef struct _point{
  int x,y;
}Point;

int N, M, map, ans = INF;
vector<Point> chicken, home;

void delivery(int cnt, int idx, int flag) {
  if(cnt == M) {
    int ret = 0;
    for(int i=0; i<home.size(); i++) {
      int dist = INF;
      for(int j=0; j<chicken.size(); j++) {
        if(flag & (1<<j)) {
          dist = min(dist, abs(home[i].x-chicken[j].x) + abs(home[i].y-chicken[j].y));
        }
      }
      ret += dist;
    }
    ans = min(ans, ret);
  }
  for(int i=idx; i<chicken.size(); i++) {
    delivery(cnt+1, i+1, flag|(1<<i));
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N>>M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>map;
      if(map == 1) home.push_back({i,j});
      if(map == 2) chicken.push_back({i,j});
    }
  }
  delivery(0, 0, 0);
  cout<<ans<<"\n";
  return 0;
}
