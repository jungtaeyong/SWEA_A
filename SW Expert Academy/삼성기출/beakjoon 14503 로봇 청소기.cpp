#include <iostream>

using namespace std;

typedef struct DIR{
	int r,c;
};

DIR dir[4]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,arr[50][50],sr,sc,d,ans;
bool check[50][50];


void solve(int r,int c){
	
	if(!check[r][c]){
		check[r][c]=true;
		ans++;
	}
	
	for(int i=0;i<4;i++){
		d=(d+3)%4;

		int nr=r+dir[d].r;
		int nc=c+dir[d].c;
		if(!check[nr][nc]&&arr[nr][nc]==0){
			solve(nr,nc);
			return;			
		}
	}

	int back=(d+2)%4;
	int br=r+dir[back].r;
	int bc=c+dir[back].c;
	if(arr[br][bc]==1){
		return;
	}else{
		solve(br,bc);
		return;
	}
	
	
}

int main(){
	cin>>n>>m;
	cin>>sr>>sc>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}		
	
	solve(sr,sc);
	cout<<ans;
}
