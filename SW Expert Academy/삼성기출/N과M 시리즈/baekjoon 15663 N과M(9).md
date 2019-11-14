### 15663 N과M(9) ★

- 선택하고 남은 수중에서 중복된 수를 거르고 출력해야하기 떄문에 까다로웠던 문제.

- 다양한 유형이 혼합되어 N과 M시리즈의 핵심문제였다. (~~어려웠다는 뜻입니다~~)

- ```C++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int n,m,ans[9];
  bool check[9];
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
  		if(!check[i]){
  			check[i]=true;
  			ans[depth]=v[i];
  			dfs(depth+1);
  			check[i]=false;
  			int repeat=1;
  			while(v[i]==v[i+repeat]){
  				repeat++;
  			}
  			i+=repeat-1;
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