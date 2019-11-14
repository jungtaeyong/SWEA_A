### 15655 N과M(6)

- 중복이 없는 수를 골라 백트래킹한다.

- 자연수가 아닌 입력받은 배열을 이용한다는 것 빼고는 같은 문제.

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
  		dfs(i+1,depth+1);
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