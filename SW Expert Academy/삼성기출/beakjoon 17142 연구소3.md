### 17142 연구소 3

- DFS와 BFS를 모두 요구하는 문제.

- 활성화 바이러스의 갯수에 따라 조합을 통해 경우의 수를 만들어(DFS) 행렬을 탐색하며(BFS) 거리(최대값)를 구하고 거리들의 최솟값을 출력한다.

- 예시를 보면 힌트를 얻을 수 있는데, 방문배열을 bool값으로 저장하지말고 int형으로 저장해 해당 배열의 거리를 저장하는것이 포인트.

- ```C++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <queue>
  #include <climits>
  using namespace std;
  
  typedef struct{
  	int x,y;
  }DIR;
  DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
  int n,m,arr[50][50],chk[50][50],ans=INT_MAX,maxnum;
  vector<int> c;
  vector<pair<int,int> > v;
  bool flag;
  bool check(){
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(arr[i][j]==0){
  				if(chk[i][j]==-1){
  					return false;	
  				}else{
  					maxnum=max(maxnum,chk[i][j]);
  				}
  			}
  		}
  	}
  	return true;
  }
  void bfs(){
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			chk[i][j]=-1;
  		}
  	}
  	maxnum=0;
  	queue<pair<int, int> > q;
  	for(int i=0;i<v.size();i++){
  		if(c[i]==1){
  			q.push({v[i].first,v[i].second});
  			chk[v[i].first][v[i].second]=0;
  		}
  	}
  	while(!q.empty()){
  		int x=q.front().first,y=q.front().second;
  		q.pop();
  		for(int i=0;i<4;i++){
  			int mx=x+dir[i].x;
  			int my=y+dir[i].y;
  			if(0<=mx&&mx<n&&0<=my&&my<n){
  				if(chk[mx][my]==-1&&arr[mx][my]!=1){
  					chk[mx][my]=chk[x][y]+1;
  					q.push({mx,my});
  				}
  			}
  		}
  	}
  	if(check()){
  		ans=min(ans,maxnum);	
  	}	
  }
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  			if(arr[i][j]==2){
  				v.push_back({i,j});
  			}
  		}
  	}
  	for(int i=0;i<v.size()-m;i++){
  		c.push_back(0);
  	}
  	for(int i=0;i<m;i++){
  		c.push_back(1);
  	}
  	do{	
  		bfs();
  	}while(next_permutation(c.begin(),c.end()));
  	if(ans==INT_MAX){
  		cout<<-1;
  	}else{
  		cout<<ans;
  	}
  	return 0;
  }
  ```

  

- 2번째 문제풀이 (2020-02-05)

```c++
#include <iostream>
#include <vector>
#include <queue>
#define WALL -10
#define SLEEP -20
using namespace std;
struct DIR{
	int r,c;
};
DIR dir[4]={{1,0},{-1,0},{0,-1},{0,1}};
int n,m,arr[50][50],ans=1000000000,map[50][50];
vector<pair<int,int> > v;
bool chk[10];
bool check(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==-1) return false;
		}
	}
	return true;
}
void solve(int start,int depth){
	if(depth==m){
		int maxnum=0;
		queue<pair<int, pair<int, int> > > q;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]==1) map[i][j]=WALL;
				if(arr[i][j]==0) map[i][j]=-1;
				if(arr[i][j]==2) map[i][j]=0;
			}
		}
		for(int i=0;i<v.size();i++){
			if(!chk[i]){
				map[v[i].first][v[i].second]=SLEEP;
			}else{
				q.push({0,{v[i].first,v[i].second}});
			}
		}
		while(!q.empty()){
			int r=q.front().second.first;
			int c=q.front().second.second;
			int cnt=q.front().first;
			q.pop();
			for(int i=0;i<4;i++){
				int nr=r+dir[i].r;
				int nc=c+dir[i].c;
				if(0<=nr&&nr<n&&0<=nc&&nc<n){
					if(map[nr][nc]==-1){
						q.push({cnt+1,{nr,nc}});
						map[nr][nc]=cnt+1;
						maxnum=max(maxnum,cnt+1);
					}else if(map[nr][nc]==SLEEP){
						q.push({cnt+1,{nr,nc}});
						map[nr][nc]=cnt+1;
					}
				}
			}
			
		}
		if(check()){
			ans=min(ans,maxnum);
		}
		
		return;
	}
	for(int i=start;i<v.size();i++){
		chk[i]=true;
		solve(i+1,depth+1);
		chk[i]=false;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==2){
				v.push_back({i,j});
			}
		}
	}
	solve(0,0);
	if(ans==1000000000){
		cout<<-1;
	}else{
		cout<<ans;
	}
}
```

