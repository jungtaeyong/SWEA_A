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
