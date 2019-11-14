### 15657 N과M(8)

- 중복해도 되지만 이전의 수보다 크거나 같아야한다.

- 이문제 또한 같은 유형의 문제.

- ```C++
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

  

