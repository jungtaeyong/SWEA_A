###  15650 N과M(2)

- 중복되지 않는 수열을 출력해야한다. (예를들어 4,1과 1,4는 같은 경우로 취급한다)

- 즉 조합을 출력하는 문제이다. DFS를 이용하여 출력한다

- ```C++
  #include <iostream>
  using namespace std;
  int n,m,arr[9];
  void dfs(int start,int depth){
  	if(depth==m){
  		for(int i=0;i<m;i++){
  			cout<<arr[i]<<" ";
  		}
  		cout<<"\n";
  	}
  	for(int i=start;i<=n;i++){
  		arr[depth]=i;
  		dfs(i+1,depth+1);
  	}
  }
  int main(){
  	cin>>n>>m;
  	dfs(1,0);
  } 
  ```
  
  

