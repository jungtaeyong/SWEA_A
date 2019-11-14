### 15654 N과M(5)

- 자기자신과 다른 수를 골라 백트래킹 하는 문제

- 자연수가 아닌 입력받은 배열을 이용한다는 점만 다르다.

- ```C++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int n,m,ans[9];
  bool check[10001];
  vector<int> v;
  void dfs(int depth){
  	if(depth==m){
  		for(int i=0;i<m;i++){
  			cout<<ans[i]<<" ";
  		}
  		cout<<"\n";
  		return;
  	}
  	for(int i=0;i<n;i++){
  		if(!check[v[i]]){
  			ans[depth]=v[i];
  			check[v[i]]=true;
  			dfs(depth+1);
  			check[v[i]]=false;
  		}
  	}
  }
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++){
  		int temp;
  		cin>>temp;
  		v.push_back(temp);
  	}
  	sort(v.begin(),v.end());
  	dfs(0);
  } 
  ```

  