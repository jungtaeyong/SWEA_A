#include <iostream>
#include <math.h>
using namespace std;

int n,gener[4][1024],ans;
bool arr[101][101];

int main(){
	// 각 방향의 세대 초기값 ex) 0방향의 0세대의 방향은0 
	gener[0][0]=0;
	gener[1][0]=1;
	gener[2][0]=2;
	gener[3][0]=3;
	for(int k=0;k<4;k++){
		for(int i=1;i<=10;i++){
			int start=pow(2,i-1);
			int end=pow(2,i);
			for(int j=start,l=1;j<end;j++,l+=2){
				gener[k][j]=gener[k][j-l]+1==4? 0 : gener[k][j-l]+1;
			}
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,d,g;
		cin>>x>>y>>d>>g;
		int end=pow(2,g);
		int curx=x;
		int cury=y;
		arr[cury][curx]=true;
		for(int j=0;j<end;j++){
			if(gener[d][j]==0){
				curx+=1;
			}else if(gener[d][j]==1){
				cury-=1;
			}else if(gener[d][j]==2){
				curx-=1;
			}else{
				cury+=1;
			}
			arr[cury][curx]=true;
		}
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(arr[i][j]&&arr[i][j+1]&&arr[i+1][j]&&arr[i+1][j+1]){
				ans++;
			}
		}
	}
	cout<<ans;
}
