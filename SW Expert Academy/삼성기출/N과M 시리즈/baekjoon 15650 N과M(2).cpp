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
	for(int i=1;i<=n;i++){
		arr[depth]=i;
		dfs(0,depth+1);
	}
}
int main(){
	cin>>n>>m;
	dfs(1,0);
} 
