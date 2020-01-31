#include <iostream>
using namespace std;
int n,m,h;
bool c[32][12];
void dfs(int depth,int maxnum, int sr, int sc){
	if(depth==maxnum){
		for(int i=1;i<=n;i++){
			int num=i;
			for(int j=1;j<=h;j++){
				if(c[j][num]){
					num++;
				}else if(c[j][num-1]){
					num--;
				}
			}
			if(i!=num){
				return;
			}
		}
		cout<<maxnum;
		exit(0);
	}
	for(int i=sr;i<=h;i++){
		for(int j= (i==sr)? sc:1 ;j<=n;j++){
			if(!c[i][j]&&!c[i][j-1]&&!c[i][j+1]){
				c[i][j]=true;
				dfs(depth+1,maxnum,i,j);
				c[i][j]=false;
			}	
		}
	}
}
int main(){
	cin>>n>>m>>h;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		c[a][b]=true;
	}
	for(int i=0;i<=3;i++){
		dfs(0,i,0,0);
	}
	cout<<-1;
}
