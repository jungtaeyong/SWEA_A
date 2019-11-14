#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,ans[9];
bool check[9];
vector<int> v;
void dfs(int start,int depth){
	if(depth==m){
		for(int i=0;i<m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start;i<n;i++){
		if(!check[i]){
			check[i]=true;
			ans[depth]=v[i];
			dfs(i+1,depth+1);
			check[i]=false;
			int repeat=1;
			while(v[i]==v[i+repeat]){
				repeat++;
			}
			i+=repeat-1;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	dfs(0,0);
} 
