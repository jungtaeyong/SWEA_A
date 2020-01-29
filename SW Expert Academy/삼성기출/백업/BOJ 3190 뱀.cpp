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
