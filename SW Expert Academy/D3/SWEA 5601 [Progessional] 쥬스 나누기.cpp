#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, N;
  cin>>T;
  for(int i=0; i<T; i++) {
    cin>>N;
    cout<<"#"<<i+1<<" ";
    for(int j=0; j<N; j++) {
      cout<<1<<"/"<<N<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
