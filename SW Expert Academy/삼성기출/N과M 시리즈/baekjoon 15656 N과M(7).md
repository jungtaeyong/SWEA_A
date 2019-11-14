### 15656 N과M(7)

- 자연수가 아닌 입력을 받은 배열로 중복수열을 나열하는 문제.

- 자연수와 입력받은 배열로 만드는것만 차이점이고 N과M(A)~N과M(A+4)은 같은 문제이다. (0<A<=4)

- ```C++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int n,m,ans[9];
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
  		ans[depth]=v[i];
  		dfs(depth+1);
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

  