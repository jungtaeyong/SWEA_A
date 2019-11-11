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
 
