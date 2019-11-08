### 16237 아기상어

- 자신의 크기보다 작은 물고기가 있다면 지속해서 먹으며 시간을 구하는 문제.

- 주의사항이 몇가지 있는데 그 중 가장 실수를 많이하는 부분이 먹을 물고기가 있지만 큰 물고기들에게 가로막혀 가지 못하는 경우이다. 이 부분을 잘 처리한다면 어렵지않게 풀 수 있다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue> 
  #include <cstring>
  #include <climits>
  using namespace std;
  typedef struct DIR{
  	int r,c;
  }DIR;
  DIR dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
  // 현재 상어의 행열sr,sc 과 최소거리와 그때의 행열좌표 tr,tc 
  int n,arr[20][20],sr,sc,ans,tr,tc,min_cnt;
  bool check[20][20],flag;
  int s_size=2,s_cnt=0;
  //먹을수 있는 물고기가 남았는지 확 인 
  bool chk(){
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(arr[i][j]!=0&&s_size>arr[i][j]){
  				return false;
  			}
  		}
  	}
  	return true;
  }
  void bfs(){
  	memset(check,0,sizeof(check));
  	min_cnt=INT_MAX;
  	tr=INT_MAX,tc=INT_MAX;
  	queue<pair<int, pair<int, int> > > q;
  	q.push({0,{sr,sc}});
  	check[sr][sc]=true;
  	while(!q.empty()){
  		int r=q.front().second.first, c=q.front().second.second;
  		int cnt=q.front().first;
  		if(arr[r][c]!=0&&arr[r][c]<s_size){
  			if(min_cnt>=cnt){
  				min_cnt=cnt;
  				// 거리가 같을 경우 위쪽행의 물고기를 먹는다.
  				// 행이같을경우 왼쪽행의 물고기를 먹는다.
  				if(tr>r){
  					tr=r;tc=c;
  				}else if(tr==r){
  					if(tc>c){
  						tc=c;
  					}
  				}
  			}
  		}
  		q.pop();
  		for(int i=0;i<4;i++){
  			int mr=r+dir[i].r;
  			int mc=c+dir[i].c;
  			if(0<=mr&&mr<n&&0<=mc&&mc<n){
  				if(!check[mr][mc]&&arr[mr][mc]<=s_size){
  					q.push({cnt+1,{mr,mc}});
  					check[mr][mc]=true;
  				}
  			}
  		}
  	}
  	//먹은 물고기 0으로 바꾸고 상어좌표 이동, 먹은 횟수나 크기 늘리기 
  	if(tr==INT_MAX){
  		flag=true;
  		return;
  	}
  	arr[tr][tc]=0;
  	sr=tr,sc=tc;
  	s_cnt++;
  	ans+=min_cnt;
  	if(s_cnt==s_size){
  		s_cnt=0;
  		s_size++;
  	}
  }
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  			if(arr[i][j]==9){
  				sr=i,sc=j;
  				arr[i][j]=0;
  			}
  		}
  	}
  	while(!flag&&!chk()){
  		bfs();
  	}
  	cout<<ans;
  }
  ```

  