#include <iostream>

using namespace std;

int T, N, M;

int pow(int depth, int num) {
  if(depth == M) {
    return num;
  }
  return pow(depth+1, num*N);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for(int i=0; i<10; i++) {
    cin>>T>>N>>M;
    cout<<"#"<<T<<" "<<pow(0, 1)<<"\n";
  }
  return 0;
}
