#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,ans[9];
vector<int> v;
void dfs(int depth){
	if(depth==m){
		for(int i=0;i<m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		ans[depth]=v[i];
		dfs(depth+1);
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
	dfs(0);
} 
