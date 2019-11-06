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
