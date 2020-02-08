#include <iostream>

using namespace std;

int ans, N, T[16], P[16], dp[21];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=1; i<=N; i++) cin>>T[i]>>P[i];
  for(int i=1; i<=N; i++) {
    dp[i+T[i]] = max(dp[i+T[i]], dp[i]+P[i]);
    dp[i+1] = max(dp[i+1], dp[i]);
  }
  cout<<dp[N+1]<<"\n";
  return 0;
}
