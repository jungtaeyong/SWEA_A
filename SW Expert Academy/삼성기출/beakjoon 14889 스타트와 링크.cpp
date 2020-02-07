#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,min1=987654321;
bool arr[20];
int a[20][20];
void dfs(int start,int depth){
	if(depth==n/2){
		vector<int> team1,team2;
		for(int i=0;i<n;i++){
			if(arr[i]){
				team1.push_back(i);
			}else{
				team2.push_back(i);
			}
		}
		int score1=0,score2=0;
		for(int i=0;i<n/2;i++){
			for(int j=i+1;j<n/2;j++){
				score1+=a[team1[i]][team1[j]]+a[team1[j]][team1[i]];
				score2+=a[team2[i]][team2[j]]+a[team2[j]][team2[i]];
			}
		}
		min1=min(abs(score1-score2),min1);
		return;
	}
	for(int i=start;i<n;i++){
		if (arr[i]==false){
            arr[i]=true;
            dfs(i+1,depth+1);
            arr[i]=false;
        }
	}
}
int main (){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	cout<<min1;
}
