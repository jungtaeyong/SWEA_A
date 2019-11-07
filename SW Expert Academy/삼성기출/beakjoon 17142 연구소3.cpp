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
