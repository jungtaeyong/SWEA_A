### 15651 N과M(3)

- DFS로 중복조합을 구현하는 문제. 당연한거지만 깊이만큼 탐색했을때 꼭 return을 써주자.

- ```C++
  #include <iostream>
  using namespace std;
  int n,m,arr[9];
  void dfs(int depth){
  	if(depth==m){
  		for(int i=0;i<m;i++){
  			cout<<arr[i]<<" ";
  		}
  		cout<<"\n";
  		return;
  	}
  	for(int i=1;i<=n;i++){
  		arr[depth]=i;
  		dfs(depth+1);
  	}
  }
  int main(){
  	cin>>n>>m;
  	dfs(0);
  } 
  ```

  

