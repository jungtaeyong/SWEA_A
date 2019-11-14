#include <iostream>
using namespace std;
int n,m,arr[9];
bool check[9];
void dfs(int start,int depth){
	if(depth==m){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=start;i<=n;i++){
		if(!check[i]){
			arr[depth]=i;
			check[i]=true;
			dfs(i+1,depth+1);
			check[i]=false;
		}
	}
}
int main(){
	cin>>n>>m;
	dfs(1,0);
} 
