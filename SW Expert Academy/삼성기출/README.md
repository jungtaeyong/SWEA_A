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



### 17779 게리맨더링 2 ★

- x,y,d1,d2값을 완전탐색하면서 (무려 4중 for문... ~~for문 지옥에 오신것을 환영합니다^^~~) 조건에 맞을 경우 다이아몬드 형태의 5구역을 구하고 조건에 따라 나머지 1,2,3,4 구역을 구해 각 지역구의 최소값을 구하는 문제.

- 5구역을 구할 때 마름모 꼴의 4개의 각 꼭지점을 기준으로 1,2,3,4 구역을 나눈다. (이게 핵심)

  - 1,2,3,4 각 구역마다 2개의 꼭지점 좌표를 사용하는데 각 꼭지점이 기준 행과 열이 되기 때문이며, 조건에 따라 삼각형모양이 아닌 사다리꼴의 형태로도 만들어질 수 있기 때문에 따로 count할 변수를 선언한다.

-  최솟값이라 minnum이라는 하나의 변수로 해결하려고 했는데 참조한 소스 코드에선 배열을 이용해 최솟값 배열을 구했다. 구해야하는 값이 많을 경우 배열을 통해 정렬하는 방식을 사용하면 더 간단하다.

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <climits>
  using namespace std;
  int n,arr[20][20],section[20][20],minnum,maxnum;
  int d1,d2,x,y,ans=INT_MAX;
  bool v[20][20];
  typedef struct POINT{
  	int x,y;
  }POINT;
  POINT point[4];
  
  void cal(){
  	int sum[5]={0,0,0,0,0};
  	// 따로따로 minnum ,maxnum 하지말고 이렇게 배열로 계산하면 더 간단하다. 
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			sum[section[i][j]-1]+=arr[i][j];
  		}
  	}
  	sort(sum,sum+5);
  	int diff=sum[4]-sum[0];
  	ans=min(ans,diff);
  }
  
  void labeling(){
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			section[i][j]=5;
  		}
  	}
  	
  	int subarea=0;
  	for(int i=0;i<point[1].x;i++){
  		// 0번 꼭짓점의 x좌표보다 크거나 같아지는 순간, 표시해야 하는 열의 갯수가 한칸씩 줄어든다. 
  		if(i>=point[0].x){
  			subarea++;	
  		}
  		for(int j=0;j<=point[0].y-subarea;j++){
  			section[i][j]=1;
  		}
  	}
  	int plusarea=0;
  	for(int i=0;i<=point[2].x;i++){
  		if(i>point[0].x){
  			plusarea++;
  		}
  		for(int j=point[0].y+1+plusarea;j<n;j++){
  			section[i][j]=2;
  		}
  	}
  	subarea=0;
  	for(int i=n-1;i>=point[1].x;i--){
  		if(i<point[3].x){
  			subarea++;
  		}
  		for(int j=0;j<point[3].y-subarea;j++){
  			section[i][j]=3;
  		}
  	}
  	plusarea=0;
  	for(int i=n-1;i>point[2].x;i--){
  		if(i<=point[3].x){
  			plusarea++;
  		}
  		for(int j=point[3].y+plusarea;j<n;j++){
  			section[i][j]=4;
  		}
  	}
  	cal();
  	
  }
  
  bool check(){
  	if(x+d1>=n ||y-d1<0){
  		return false;
  	}
  	if(x+d2>=n || y+d2>=n){
  		return false;
  	}
  	if(x+d1+d2>=n|| y-d1+d2>=n){
  		return false;
  	}
  	if(x+d2+d1>=n||y+d2-d1<0){
  		return false;
  	}
  	return true;
  }
  
  void solve(){
  	for(x=1;x<n;x++){
  		for(y=1;y<n;y++){
  			for(d1=1;d1<=y;d1++){
  				for(d2=1;d2<n-y;d2++){
  					if(check()){
  						point[0].x=x; point[0].y=y;
  						point[1].x=x+d1;point[1].y=y-d1;
  						point[2].x=x+d2;point[2].y=y+d2;
  						point[3].x=x+d1+d2;point[3].y=y-d1+d2;
  						labeling();
  					}
  				}
  			}
  		}
  	}
  }
  
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	solve();
  	cout<<ans;
  }
  ```



### 17837 새로운 게임2 ★

- 문제를 제대로 이해 못해서 이틀이나 걸렸다. (~~한 문제에 이틀이나 쓰는 남자가 있다?~~)

- 턴종료시 4개일 때가 아니라, **턴내에 4개의 말이 쌓이면 바로 출력**하면 된다.

- 대신 150줄이 넘었던 코드를 리팩토링을 통해 좀 더 효율적으로 구현했다. 하지만 이틀동안 한 문제만 고민하는 과정이 (~~너무너무너무~~)고통스러웠다..

- 참조자(&)와 find함수에 대해 배웠고 이터레이터를 활용하여 push_back, erase, reverse 메서드를 사용했다.

  - 참조자
    - 해당 메모리 주소만을 가르키기 때문에 포인터처럼 이동할 수 있는 개념은 아니다. 변수와 다르게 값을 복사하는 것이 아니라, 해당 주소를 가르키기 때문에 mutable하게 값을 바꿀 수 있다.
  - find(v.begin(),v.end(),value)
    - v의 시작 이터레이터부터 v의 마지막 이터레이터 까지 탐색하며 value값을 찾았을 경우 그 주소의 이터레이터를 반환, 아닐시 v.end()반환
  - reverse(iterater start,iterater end)
    - start부터 end의 이터레이터 범위까지 reverse한다. 

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  
  using namespace std;
  
  int n,k,arr[13][13],arr_cnt[13][13],ans,cnt;
  vector<pair<int,pair<int,int> > > v;
  vector<int> move_c[13][13];
  typedef struct DIR{
  	int r,c;
  }DIR;
  DIR dir[5]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
  bool flag;
  
  bool chess_count(){
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			if(move_c[i][j].size()>=4){
  				return true;
  			}
  		}
  	}
  	return false;
  }
  
  void solve(){
  	for(int i=0;i<v.size();i++){
  		int vr=v[i].second.first,vc=v[i].second.second,vdir=v[i].first;
  		int mr=vr+dir[vdir].r,mc=vc+dir[vdir].c;
  		if(mr<1||n<mr||mc<1||n<mc||arr[mr][mc]==2){
  			if(vdir%2==0){
  				vdir--;
  			}else{
  				vdir++;
  			}
  			v[i].first=vdir;
  			mr=vr+dir[vdir].r,mc=vc+dir[vdir].c;
  			if(mr<1||n<mr||mc<1||n<mc||arr[mr][mc]==2){
  				continue;
  			}
  		}
  		vector<int>::iterator it;
  		vector<int> &cur =move_c[vr][vc];
  		vector<int> &next =move_c[mr][mc];
  		it=find(cur.begin(),cur.end(),i+1);
  		if(arr[mr][mc]==1){
  			reverse(it,cur.end());
  		}
  		vector<int>::iterator s;
  		for(s=it;s!=cur.end();++s){
  			v[*s-1].second.first=mr;
  			v[*s-1].second.second=mc;
  			next.push_back(*s);
  		}
  		cur.erase(it,cur.end());
  		flag=chess_count();
  		if(flag){
  			return;
  		}
  	}
  }
  int main(){
  	cin>>n>>k;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	for(int i=1;i<=k;i++){ 
  		int temp_r,temp_c,temp_dir;
  		cin>>temp_r>>temp_c>>temp_dir;
  		v.push_back({temp_dir,{temp_r,temp_c}});
  		move_c[temp_r][temp_c].push_back(i);
  	}
  	while(ans<=1000 && !flag){
  		solve();
  		ans++;
  	}
  	if(ans>1000){
  		cout<<-1;
  	}else{
  		cout<<ans;
  	}
  }
  ```



### 16235 나무 재테크

- 조건에 따라 봄, 여름, 가을, 겨울 조건을 구현하면 되는 문제.
- 핵심은 봄이였는데 iterator를 통해 값을 증가시키려고 `*it++`을 쓰면 에러가 난다. 후위증감연산자의 우선순위가 높기때문이다. 따라서 `(*it)++`을 써야한다.
- iterator를 통해 erase, insert메서드에 익숙해졌고, iterator사용시 뿐만아니라 연산시 연산자의 우선순위를 고려해야 한다는 것을 배웠다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  int n,m,k,arr[11][11],food[11][11],sum,y;
  vector<int> v[11][11];
  vector<int> dtree[11][11];
  typedef struct DIR{
  	int r,c;
  }DIR;
  DIR dir[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
  
  void solve(){
  	// 봄 
  	vector<int>::iterator it;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			sort(v[i][j].begin(),v[i][j].end());
  			for(it=v[i][j].begin();it!=v[i][j].end();it++){
  				if(food[i][j]>=*it){
  					food[i][j]-=*it;
  					(*it)++;
  				}else{
  					dtree[i][j].insert(dtree[i][j].end(),it,v[i][j].end());
  					v[i][j].erase(it,v[i][j].end());
  					break;
  				}
  			}
  		}
  	}
  	//여름
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			for(it=dtree[i][j].begin();it!=dtree[i][j].end();it++){
  				food[i][j]+=(*it)/2;
  			}
  			dtree[i][j].clear();
  		}
  	}
  	//가을
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			for(int k=0;k<v[i][j].size();k++){
  				if(v[i][j][k]%5==0){
  					for(int k=0;k<8;k++){
  						int mr=i+dir[k].r;
  						int mc=j+dir[k].c;
  						if(1<=mr&&mr<=n&&1<=mc&&mc<=n){
  							v[mr][mc].push_back(1);
  						}
  					}
  				}
  			}
  		}
  	}
  	//겨울
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			food[i][j]+=arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			sum+=v[i][j].size();
  		}
  	}
  	y++;
  }
  
  int main(){
  	cin>>n>>m>>k;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			food[i][j]=5;
  		}
  	}
  	for(int i=0;i<m;i++){
  		int temp_x,temp_y,temp_year;
  		cin>>temp_x>>temp_y>>temp_year;
  		v[temp_x][temp_y].push_back(temp_year);
  	}
  	while(y!=k){
  		sum=0;
  		solve();
  	}
  	cout<<sum;
  }
  ```




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

  

