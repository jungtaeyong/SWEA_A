#include <iostream>

using namespace std;

const int MAX = 1e6;
int N, B, C, A[MAX];
long long ans;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++) cin>>A[i];
  cin>>B>>C;
  for(int i=0; i<N; i++) {
    ans++;
    A[i] -= B;
    if(A[i] > 0) {
      ans += A[i] / C;
      if(A[i] % C) ans++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
