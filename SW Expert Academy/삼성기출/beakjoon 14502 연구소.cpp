#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct DIR{
	int r,c;
};
DIR dir[4]={{1,0},{-1,0},{0,-1},{0,1}};
int n,m,arr[8][8],chk[8][8],map[8][8],ans;
bool visit[8][8];
int testcnt=0;
bool flag;
void dfs(int r,int c,int depth){
	if(depth==3){
		memset(visit,0,sizeof(visit));
		queue<pair<int, int> > q;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				map[i][j]=chk[i][j];
				if(map[i][j]==2){
					q.push({i,j});
				}
			}
		}
		while(!q.empty()){
			int row=q.front().first;
			int col=q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int nr=row+dir[i].r;
				int nc=col+dir[i].c;
				if(0<=nr&&nr<n&&0<=nc&&nc<m&&map[nr][nc]==0){
					map[nr][nc]=2;
					q.push({nr,nc});
				}
			}
		}
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==0)num++;
			}
		}
		ans=max(ans,num);
		return;
	}
	for(int i=r;i<n;i++){
		for(int j=(i==r ? c : 0) ;j<m;j++){
			if(chk[i][j])continue;
			chk[i][j]=1;
			dfs(i,j+1,depth+1);
			chk[i][j]=0;
		}
	}
	flag=true;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			chk[i][j]=arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!chk[i][j]){
				dfs(i,j,0);
			}
		}
	}
	cout<<ans;	
}
