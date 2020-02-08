#include <iostream>

using namespace std;

int N, A[12], op[4],  minr = 1e9, maxr = -1e9;

void calc(int idx, int val) {
  if(idx == N) {
    minr = min(minr, val);
    maxr = max(maxr, val);
    return;
  }
  if(op[0]) {
    op[0]--;
    calc(idx+1, val+A[idx]);
    op[0]++;
  }
  if(op[1]) {
    op[1]--;
    calc(idx+1, val-A[idx]);
    op[1]++;
  }
  if(op[2]) {
    op[2]--;
    calc(idx+1, val*A[idx]);
    op[2]++;
  }
  if(op[3]) {
    op[3]--;
    calc(idx+1, val/A[idx]);
    op[3]++;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) cin>>A[i];
  for(int i=0; i<4; i++) cin>>op[i];
  calc(1, A[0]);
  cout<<maxr<<"\n"<<minr<<"\n";
  return 0;
}
