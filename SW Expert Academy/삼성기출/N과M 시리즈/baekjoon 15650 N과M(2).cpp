#include <iostream>
using namespace std;
int n,m,arr[9];
void dfs(int start,int depth){
	if(depth==m){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=start;i<=n;i++){
		arr[depth]=i;
		dfs(i+1,depth+1);
	}
}
int main(){
	cin>>n>>m;
	dfs(1,0);
} 
