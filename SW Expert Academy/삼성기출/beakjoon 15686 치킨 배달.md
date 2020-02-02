### 15686. 치킨 배달

- 조합을 이용한 경우의 수를 이용하여 살려야 할 갯수 만큼의 치킨 집을 선택한 후 최소 치킨거리를 구한다.

- 예전에는 next_permutation을 이용해 문제를 풀었지만, m과n 시리즈를 풀면서 순열, 조합, 중복조합 등을 재귀함수 형태(dfs)로 구현하며 연습했기 때문에 dfs를 이용하여 풀었다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #define INF 10000000
  using namespace std;
  int n,m,arr[51][51],ans=INF;
  vector<pair<int ,int > > h,c;
  bool check[13];
  void dfs(int start,int depth){
  	
  	if(depth==m){
  		int ret=0;
  		for(int i=0;i<h.size();i++){
  			int num=INF;
  			for(int j=0;j<c.size();j++){
  				if(!check[j])continue;
  				num=min(num,abs(h[i].first-c[j].first)+abs(h[i].second-c[j].second));
  			}
  			ret+=num;
  		}
  		ans=min(ans,ret);
  	}
  	for(int i=start;i<c.size();i++){
  		check[i]=true;
  		dfs(i+1,depth+1);
  		check[i]=false;
  	}
  }
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  			if(arr[i][j]==1){
  				h.push_back({i,j});
  			}else if(arr[i][j]==2){
  				c.push_back({i,j});
  			}
  		}
  	}
  	dfs(0,0);
  	cout<<ans;
  } 
  ```

  