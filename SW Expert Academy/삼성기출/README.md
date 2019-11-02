# 삼성기출 문제집

### 13460 구슬탈출2 ★★

- 경우의수(예외처리) 끝판왕 문제. (~~경우의 수 지옥을 경험해보자~~)

1. 빨간 구슬과 파란 구슬이 일직선 상에 없음

   1.1) 빨간 구슬이 가는 길에 구멍이 있는 경우 --> 탈출 성공

   1.2) 파란 구슬이 가는 길에 구멍이 있는 경우 --> 탈출 실패

   1.3) 구멍이 없는 경우 --> 구슬들을 최대한 이동한 후 큐에 push

2. 빨간 구슬이 가는 길에 파란 구슬이 있는 경우

   2.1) 파란 구슬 앞에 구멍이 있는 경우 --> 탈출 성공

   2.2) 파란 구슬 뒤에 구멍이 있는 경우 --> 탈출 실패

   2.3) 구멍이 없는 경우 --> 파란 구슬은 최대한 이동, 빨간 구슬은 한 칸 덜 이동한 후에 큐에 push

3. 파란 구슬이 가는 길에 빨간 구슬이 있는 경우

   3.1) 구멍이 있는 경우 --> 탈출 실패

   3.2) 구멍이 없는 경우 --> 빨간 구슬은 최대한 이동, 파란 구슬은 한 칸 덜 이동한 후에 큐에 push

- 위의 과정을 bfs 각 상태 공간마다 시행하고 깊이가 10이 되면 종료하게 구현하면 된다.

```c++
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Marble{
	int cnt,rx,ry,bx,by;
};

typedef struct _DIR{
	int x,y;
}DIR;

DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,ans=-1,tx,ty;
string arr[10];
queue <Marble> q;
void bfs(){
	int rsx,rsy,bsx,bsy;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='R'){
				rsx=i,rsy=j;
			}
			if(arr[i][j]=='B'){
				bsx=i,bsy=j;
			}
			if(arr[i][j]=='O'){
				tx=i,ty=j;
			}
		}
	}
	q.push({0,rsx,rsy,bsx,bsy});
	while(!q.empty()){
		int rx=q.front().rx,ry=q.front().ry,bx=q.front().bx,by=q.front().by;
		int cnt=q.front().cnt;
		q.pop();
		if(cnt==10){
			break;
		}
		for(int i=0;i<4;i++){
			int rex=0;
			int blue=0;
			int rmove=0;
			int mrx=rx+dir[i].x,mry=ry+dir[i].y;
			while(arr[mrx][mry]!='#'){
				rmove++;
				if(mrx==bx&&mry==by){
					blue=rmove;
				}
				if(arr[mrx][mry]=='O'){
					rex=rmove;
				}
				mrx+=dir[i].x;
				mry+=dir[i].y;
			}
			bool bex=false;
			bool red=false;
			int mbx,mby;
			int bmove=0;
			mbx=bx+dir[i].x;
			mby=by+dir[i].y;
			while(arr[mbx][mby]!='#'){
				bmove++;
				if(mbx==rx&&mby==ry){
					red=true;
				}
				if(arr[mbx][mby]=='O'){
					bex=true;
				}
				mbx+=dir[i].x;
				mby+=dir[i].y;
			}
			if(!blue&&!red){
				if(rex){
					ans=cnt+1;
					return;
				}
				else if(bex){
					continue;
				}else{
					q.push({cnt+1,rx+dir[i].x*rmove,ry+dir[i].y*rmove,bx+dir[i].x*bmove,by+dir[i].y*bmove});				
				}
			}else if(blue){
				if(rex){
					if(rex<blue){
						ans=cnt+1;
						return;
					}
					continue;
				}else{
					rmove--;
					q.push({cnt+1,rx+dir[i].x*rmove,ry+dir[i].y*rmove,bx+dir[i].x*bmove,by+dir[i].y*bmove});
				}
			}else{
				if(rex){
					continue;
				}
				else{
					bmove--;
					q.push({cnt+1,rx+dir[i].x*rmove,ry+dir[i].y*rmove,bx+dir[i].x*bmove,by+dir[i].y*bmove});
				}
			}
		}
	}	
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	bfs();
	cout<<ans;
}
```

- 연습하기엔 너무나 좋은 문제이다. 반복연습을 통해 모든 경우의 수를 생각해보고, 변수들이 무엇을 위해 필요한지 하나하나 뜯어보자.



### 3190 뱀 ★

- 뱀의 머리가 벽에 부딪히거나 자신의 몸에 부딪혔을 때 게임이 종료되고 그 시점의 시간을 구하는 문제
- 뱀의 자취를 큐로 만들어 저장하는 것이 핵심

- ```c++
  #include <iostream>
  #include <queue>
  using namespace std;
  enum{
  	EMPTY=0,
  	SNAKE,
  	APPLE
  };
  int arr[101][101] = {0};
  int n,k,l,sec,dirnum=100;
  queue<pair<int, char> > dq; 
  queue<pair<int, int> >snake;
  typedef struct DIR{
  	int x,y;
  }DIR;
  const DIR dir[4]={{0,1},{1,0},{0,-1},{-1,0}};
  void bfs(){
  	snake.push(make_pair(1,1));
  	arr[1][1]=SNAKE;
  	pair<int, int> dqnum;
  	if(!dq.empty()){
  		dqnum=dq.front();
  		dq.pop();
  	}
  	while(1){
  		int sx=snake.back().first,sy=snake.back().second;
  		int dx = dir[dirnum % 4].x, dy = dir[dirnum % 4].y;
  		int nx = sx+dx, ny = sy+dy;
  		if(nx < 1 || nx > n || ny < 1 || ny > n || arr[nx][ny]==SNAKE){
  			return;
  		} else {
  			if(arr[nx][ny]!=APPLE){
  				pair<int, int> tail = snake.front();
  				arr[tail.first][tail.second] = EMPTY;
  				snake.pop();
  			}
  			arr[nx][ny] = SNAKE;
  			snake.push(make_pair(nx,ny));
  		}
  		sec++;
  		if(sec==dqnum.first){
  			dirnum += dqnum.second == 'L' ? -1 : 1;
  			if(!dq.empty()) {
  				dqnum = dq.front();
  				dq.pop();	
  			}
  		}	
  	}
  }
  
  int main(){
  	cin>>n;
  	cin>>k;
  	for(int i=0;i<k;i++){
  		int x, y;
  		cin>>x>>y;
  		arr[x][y]=APPLE;
  	}
  	cin>>l;
  	for(int i=0;i<l;i++){
  		int time;
  		char rotate;
  		cin>>time>>rotate;
  		dq.push(make_pair(time,rotate));
  	}
  	bfs();	
  	cout<<sec+1<<"\n";
  }
  ```



### 13458 시험 감독

- 삼성 SW 역량 테스트 기출 문제중 가장 쉬운 문제가 아닐까 생각한다.

- 그리디적인 접근방식으로 풀면 바로 풀리는 문제

- 다만 총 감독관 수는 int형을 초과하기 때문에 long long으로 풀어주는게 관건

- ```c++
  #include <iostream>
  using namespace std;
  int n,b,c,arr[1000001];
  long long cnt=0;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	cin>>b>>c;	
  	for(int i=0;i<n;i++){
  		arr[i]-=b;
  		cnt++;
  		if(arr[i]>0){
  			cnt+=arr[i]/c+!!(arr[i]%c);
  		}
  	}
  	cout<<cnt;
  }
  ```



