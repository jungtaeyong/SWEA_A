#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct DIR{
	int r,c;
}DIR;
int n,arr[21][21],ans;
void check(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans=max(ans,arr[i][j]);
		}
	}
}
void dfs(int depth){
	if(depth==5){
		check();
		return;
	}
	//0:left 1:right 2:up 3:down
	for(int i=0;i<4;i++){
		int temp[21][21];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				temp[i][j]=arr[i][j];
			}
		}
		if(i==2||i==3){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					arr[j][k]=temp[k][j];
				}
			}
		}
		vector<int> v[n];
		if(i==1||i==3){
			for(int j=0;j<n;j++){
				reverse(arr[j],arr[j]+n);
			}
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(arr[j][k]!=0){
					int l = k+1;
					while(l < n && arr[j][l] == 0) {
						l++;
					}
					if(l >= n || arr[j][k] != arr[j][l]) {
						v[j].push_back(arr[j][k]);
					} else {
						v[j].push_back(arr[j][k]*2);
						k=l;
					}
				}
			}
		}
		for(int j=0;j<n;j++){
			for(int k=v[j].size()+1;k<=n;k++){
				v[j].push_back(0);
			}
		}	
		for(int j=0;j<n;j++){
			for(int k=0;k<v[j].size();k++){
				arr[j][k]=v[j][k];
			}
		}
		dfs(depth+1);
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				arr[j][k]=temp[j][k];
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	dfs(0);
	cout<<ans;
}
