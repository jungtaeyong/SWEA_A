#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1e9
using namespace std;

int ans = MAX, N, S[20][20];
vector<int> s, l;

void select(int idx, int cnt, int flag) {
  if(cnt == N/2) {
    s.clear(), l.clear();
    int ss = 0, sl = 0;
    for(int i=0; i<N; i++) {
      if(flag & (1<<i)) s.push_back(i);
      else l.push_back(i);
    }
    for(int i=0; i<N/2; i++) {
      for(int j=i+1; j<N/2; j++) {
        ss += S[s[i]][s[j]] + S[s[j]][s[i]];
        sl += S[l[i]][l[j]] + S[l[j]][l[i]];
      }
    }
    ans = min(ans, abs(ss-sl));
    return;
  }
  for(int i=idx; i<N; i++) {
    select(i+1, cnt+1, flag|(1<<i));
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin>>S[i][j];
    }
  }
  select(0,0,0);
  cout<<ans<<"\n";
  return 0;
}
