#include <iostream>
#include <vector>
using namespace std;

vector<pair <int, int> > v;
int n,m,ans=10000,arr[8][8],map[8][8];

void checking(int d,int r,int c){
	if(d==0){
		for(int i=c;i<m;i++){
			if(map[r][i]==6) return;
			if(map[r][i]==0) map[r][i]=7;
		}
	}else if(d==1){
		for(int i=r;i<n;i++){
			if(map[i][c]==6) return;
			if(map[i][c]==0) map[i][c]=7;
		}
	}else if(d==2){
		for(int i=c;i>=0;i--){
			if(map[r][i]==6) return;
			if(map[r][i]==0) map[r][i]=7;
		}
	}else if(d==3){
		for(int i=r;i>=0;i--){
			if(map[i][c]==6) return;
			if(map[i][c]==0) map[i][c]=7;
		}
	}
}

int cnt=0;
void solve(int depth){
	if(depth==v.size()){
		int ret=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==0) ret++;
			}
		}
		ans=min(ans,ret);
		return;
	}
	
	int r=v[depth].first;
	int c=v[depth].second;
	int temp[8][8]; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			temp[i][j]=map[i][j]; 
		}
	}
	if(arr[r][c]==1){
		for(int d=0;d<4;d++){
			checking(d,r,c);
			solve(depth+1);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					map[i][j]=temp[i][j];
				}
			}
		}
	}else if(arr[r][c]==2){
		for(int d=0;d<4;d++){
			checking(d,r,c);
			checking((d+2)%4,r,c);
			solve(depth+1);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					map[i][j]=temp[i][j];
				}
			}
		}
	}else if(arr[r][c]==3){
		for(int d=0;d<4;d++){
			checking(d,r,c);
			checking((d+3)%4,r,c);
			solve(depth+1);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					map[i][j]=temp[i][j];
				}
			}
		}
	}else if(arr[r][c]==4){
		for(int d=0;d<4;d++){
			checking(d,r,c);
			checking((d+2)%4,r,c);
			checking((d+3)%4,r,c);
			solve(depth+1);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					map[i][j]=temp[i][j];
				}
			}
		}
	}else if(arr[r][c]==5){
		for(int d=0;d<4;d++){
			checking(d,r,c);
			checking((d+1)%4,r,c);
			checking((d+2)%4,r,c);
			checking((d+3)%4,r,c);
		}
		solve(depth+1);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			map[i][j]=arr[i][j];
			if(1<=arr[i][j]&&arr[i][j]<=5){
				v.push_back({i,j});
			}
		}
	}
	solve(0);
	cout<<ans;
} 
