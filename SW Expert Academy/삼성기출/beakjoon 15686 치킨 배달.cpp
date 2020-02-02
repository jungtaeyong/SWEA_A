#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000
using namespace std;
int n,m,arr[51][51],ans=INF;
vector<pair<int ,int > > h,c;
bool check[13];
void dfs(int start,int depth){
	if(depth==m){
		int ret=0;
		for(int i=0;i<h.size();i++){
			int num=INF;
			for(int j=0;j<c.size();j++){
				if(!check[j])continue;
				num=min(num,abs(h[i].first-c[j].first)+abs(h[i].second-c[j].second));
			}
			ret+=num;
		}
		ans=min(ans,ret);
	}
	for(int i=start;i<c.size();i++){
		check[i]=true;
		dfs(i+1,depth+1);
		check[i]=false;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				h.push_back({i,j});
			}else if(arr[i][j]==2){
				c.push_back({i,j});
			}
		}
	}
	dfs(0,0);
	cout<<ans;
} 
