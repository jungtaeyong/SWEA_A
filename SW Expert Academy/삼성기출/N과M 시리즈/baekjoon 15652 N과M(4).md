### 15652 N과M(4)

- 중복해서 뽑아도 되지만 뽑은 수보다 높거나 같아야한다.

- 백트래킹 (DFS)을 이용하여 간단하게 풀 수 있다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,m,arr[9];
  void dfs(int start,int depth){
  	if(depth==m){
  		for(int i=0;i<m;i++){
  			cout<<arr[i]<<" ";
  		}
  		cout<<"\n";
  		return;
  	}
  	for(int i=start;i<=n;i++){
  		arr[depth]=i;
  		dfs(i,depth+1);
  	}
  }
  int main(){
  	cin>>n>>m;
  	dfs(1,0);
  } 
  ```

  

