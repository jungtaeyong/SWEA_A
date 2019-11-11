### 16234 인구이동

- [BOJ 2667 단지번호붙이기]( https://www.acmicpc.net/problem/2667 )의 상위호환 문제.

- BFS로 조건에 부합하는 배열을 방문하여 각 나라의 평균을 구하는데 이때 큐를 하나 더 선언하여 배열의 인덱스를 기록한다. 이부분은 [BOJ 3190 뱀]( https://www.acmicpc.net/problem/3190 )문제와 비슷한데 조건에 부합하는 구간의 인덱스값(흔적)을 기록하는 것이다. 흔적을 기록하는 큐는 BFS로 방문하는 큐와 다르게 push만 해준다. BFS를 다돌고 난 이후에는 흔적을 기록하는 큐에 있는 해당 인덱스의 배열값을 바꿔주면 된다. 보통은 코드를 설명하지만 간혹 글을 통한 설명보다 코드를 보는것이 이해가 더 잘되는 경우가 있다. 이부분이 그경우이다. (~~사실 내가 설명을 잘 못하는것 같다~~)

- ```c++
  #include <iostream>
  #include <queue>
  #include <cstring>
  #include <stdlib.h>
  using namespace std;
  typedef struct DIR{
  	int r,c;
  }DIR;
  DIR dir[4]={{1,0},{-1,0},{0,-1},{0,1}};
  int n,l,r,arr[51][51],ans; 
  bool chk[51][51];
  bool check(){
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n-1;j++){
  			if(i==n-1){
  				int nextnum=abs(arr[i][j]-arr[i][j+1]);	
  				if(l<=nextnum&&nextnum<=r){
  					return false;
  				}
  			}else{
  				int nextnum=abs(arr[i][j]-arr[i][j+1]);
  				int downnum=abs(arr[i][j]-arr[i+1][j]);
  				if(l<=nextnum&&nextnum<=r){
  					return false;
  				}
  				if(l<=downnum&&downnum<=r){
  					return false;
  				}
  			}
  		}
  	}
  	return true;
  }
  
  void bfs(int x,int y){
  	int num=0,sum=0;
  	queue<pair<int,int> > q;
  	queue<pair<int,int> > qq;
  	q.push({x,y});
  	qq.push({x,y});
  	chk[x][y]=true;
  	num++;
  	sum+=arr[x][y];
  	while(!q.empty()){
  		int row=q.front().first,col=q.front().second;
  		q.pop();
  		for(int i=0;i<4;i++){
  			int mr=row+dir[i].r;
  			int mc=col+dir[i].c;
  			if(0<=mr&&mr<n&&0<=mc&&mc<n){
  				if(!chk[mr][mc]){
  					int nextnum=abs(arr[row][col]-arr[mr][mc]);
  					if(l<=nextnum&&nextnum<=r){
  						q.push({mr,mc});
  						qq.push({mr,mc});
  						chk[mr][mc]=true;
  						num++;
  						sum+=arr[mr][mc];
  					}	
  				}
  			}
  		}
  	}
  	int movenum=sum/num;
  	while(!qq.empty()){
  		int rr=qq.front().first,cc=qq.front().second;
  		qq.pop();
  		arr[rr][cc]=movenum;
  	}
  }
  void solve(){
  	memset(chk,0,sizeof(chk));
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(!chk[i][j]){
  				bfs(i,j);
  			}
  		}	
  	}
  }
  int main(){
  	cin>>n>>l>>r;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	while(!check()){
  		solve();
  		ans++;
  	}
  	cout<<ans;
  } 
  ```

  