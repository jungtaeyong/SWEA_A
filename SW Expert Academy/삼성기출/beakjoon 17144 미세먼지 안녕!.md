### 17144 미세먼지 안녕! ★

- 복잡해 보이지만 로직자체는 어렵지 않다. 주어진 조건대로만 구현하면 되는데 문제는 미세먼지가 이동하는 과정에서 for문설정을 잘못하면 무한하게 틀렸습니다가 나오게된다. 주의하자.

- 행렬에서 4방향으로 조건에 따라 행렬값을 바꿔야하는데 4방향에서 bfs 반드시 써야 된다고 생각했는데 큐를 쓰지만 bfs를 쓰는 것은 아니다.

- 틀렸습니다가 나왔는데 반례가 생각이 안날땐 기존의 예시가 내가 생각한 과정을 거치는지 확인해보자.

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  using namespace std;
  
  typedef struct DIR{
  	int x,y;
  }DIR;
  int r,c,t,arr[100][100],sec,cnt,ans;
  vector<pair<int, int > > uv(1),dv(1);
  DIR dir[4]={{1,0},{-1,0},{0,-1},{0,1}};
  
  void solve(){
  	queue<pair<int, pair<int,int> > > qq;
  	
  	for(int i=0;i<r;i++){
  		for(int j=0;j<c;j++){
  			if(arr[i][j]!=0&&arr[i][j]!=-1){
  				cnt=0;
  				for(int k=0;k<4;k++){
  					int mx=i+dir[k].x;
  					int my=j+dir[k].y;
  					if(0<=mx&&mx<r&&0<=my&&my<c&&arr[mx][my]!=-1){
  						qq.push(make_pair(arr[i][j]/5,make_pair(mx,my)));
  						cnt++;
  					}
  				}
  				arr[i][j]=arr[i][j]-(arr[i][j]/5*cnt);
  			}
  		}
  	}
  	
  	while(!qq.empty()){
  		int xx=qq.front().second.first,yy=qq.front().second.second;
  		int value=qq.front().first;
  		qq.pop();
  		arr[xx][yy]+=value;
  	}
  
  	//공기청정기 작동
  	int ux=uv[0].first,uy=uv[0].second;
  	int dx=dv[0].first,dy=dv[0].second;
  	for(int i=ux-1;i>0;i--){
  		arr[i][0]=arr[i-1][0];
  	}
  	for(int i=0;i<c-1;i++){
  		arr[0][i]=arr[0][i+1];
  	}
  	for(int i=0;i<ux;i++){
  		arr[i][c-1]=arr[i+1][c-1];
  	}
  
  	for(int i=c-1;i>1;i--){
  		arr[ux][i]=arr[ux][i-1];
  	}
  	arr[ux][1]=0;	
  	for(int i=dx+1;i<r-1;i++){
  		arr[i][0]=arr[i+1][0];
  	}
  	for(int i=0;i<c-1;i++){
  		arr[r-1][i]=arr[r-1][i+1];
  	}
  	for(int i=r-1;i>dx;i--){
  		arr[i][c-1]=arr[i-1][c-1];
  	}
  	for(int i=c-1;i>0;i--){
  		arr[dx][i]=arr[dx][i-1];
  	}
  	arr[dx][1]=0;
  	sec++;
  }
  
  int main(){
  	
  	cin>>r>>c>>t;
  	for(int i=0;i<r;i++){
  		for(int j=0;j<c;j++){
  			cin>>arr[i[j];
  			if(arr[i][j]==-1){
  				if(uv[0].first==0){
  					uv[0].first=i,uv[0].second=j;
  				}else{
  					dv[0].first=i,dv[0].second=j;
  				}
  				
  			}
  		}
  	}
  	while(sec!=t){
  		solve();	
  	}
  	for(int i=0;i<r;i++){
  		for(int j=0;j<c;j++){
  			ans+=arr[i][j];
  		}
  	}
  	cout<<ans+2;
  }
  ```

