### 15649 N과 M(1)

- 모든 경우의 수를 출력해야하고 순서를 따지기 때문에 (예를들어 1,4와 4,1은 다른경우) 순열로 볼 수 있다.

- 재귀를 이용하여 DFS기법과 같다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,m,arr[9];
  bool check[9];
  void dfs(int start,int depth){
  	if(depth==m){
  		for(int i=0;i<m;i++){
  			cout<<arr[i]<<" ";
  		}
  		cout<<"\n";
  	}
  	for(int i=1;i<=n;i++){
  		if(check[i]==false){
  			arr[depth]=i;
  			check[i]=true;
  			dfs(start+1,depth+1);
  			check[i]=false;
  		}
  	}
  }
  int main(){
  	cin>>n>>m;
  	dfs(1,0);
  } 
  ```

  