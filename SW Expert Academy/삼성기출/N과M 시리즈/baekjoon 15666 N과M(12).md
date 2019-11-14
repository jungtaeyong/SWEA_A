### 15666 N과M(12)

- N과M시리즈의 마지막 문제. N과M(9)문제가 까다로워서 오래걸렸지만 그 이후의 문제는 순열,조합,중복조합 등 간단한 조건이기 때문에 어렵지 않게 풀 수 있었다. 

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int n,m,ans[9];
  vector<int> v;
  void dfs(int start,int depth){
  	if(depth==m){
  		for(int i=0;i<m;i++){
  			cout<<ans[i]<<" ";
  		}
  		cout<<"\n";
  		return;
  	}
  	for(int i=start;i<n;i++){
  		ans[depth]=v[i];
  		dfs(i,depth+1);
  		int repeat=1;
  		while(v[i]==v[i+repeat]){
  			repeat++;
  		}
  		i+=repeat-1;
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
  	dfs(0,0);
  } 
  ```

