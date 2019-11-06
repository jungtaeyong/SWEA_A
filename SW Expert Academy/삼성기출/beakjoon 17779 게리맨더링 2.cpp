#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n,arr[20][20],section[20][20],minnum,maxnum;
int d1,d2,x,y,ans=INT_MAX;
bool v[20][20];
typedef struct POINT{
	int x,y;
}POINT;
POINT point[4];
void cal(){
	int sum[5]={0,0,0,0,0};
	// 따로따로 minnum ,maxnum 하지말고 이렇게 배열로 계산하면 더 간단하다. 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum[section[i][j]-1]+=arr[i][j];
		}
	}
	sort(sum,sum+5);
	int diff=sum[4]-sum[0];
	ans=min(ans,diff);
}

void labeling(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			section[i][j]=5;
		}
	}
	int subarea=0;
	for(int i=0;i<point[1].x;i++){
		// 0번 꼭짓점의 x좌표보다 크거나 같아지는 순간, 표시해야 하는 열의 갯수가 한칸씩 줄어든다. 
		if(i>=point[0].x){
			subarea++;	
		}
		for(int j=0;j<=point[0].y-subarea;j++){
			section[i][j]=1;
		}
	}
	int plusarea=0;
	for(int i=0;i<=point[2].x;i++){
		if(i>point[0].x){
			plusarea++;
		}
		for(int j=point[0].y+1+plusarea;j<n;j++){
			section[i][j]=2;
		}
	}
	subarea=0;
	for(int i=n-1;i>=point[1].x;i--){
		if(i<point[3].x){
			subarea++;
		}
		for(int j=0;j<point[3].y-subarea;j++){
			section[i][j]=3;
		}
	}
	plusarea=0;
	for(int i=n-1;i>point[2].x;i--){
		if(i<=point[3].x){
			plusarea++;
		}
		for(int j=point[3].y+plusarea;j<n;j++){
			section[i][j]=4;
		}
	}
	cal();
}

bool check(){
	if(x+d1>=n ||y-d1<0){
		return false;
	}
	if(x+d2>=n || y+d2>=n){
		return false;
	}
	if(x+d1+d2>=n|| y-d1+d2>=n){
		return false;
	}
	if(x+d2+d1>=n||y+d2-d1<0){
		return false;
	}
	return true;
}

void solve(){
	for(x=1;x<n;x++){
		for(y=1;y<n;y++){
			for(d1=1;d1<=y;d1++){
				for(d2=1;d2<n-y;d2++){
					if(check()){
						point[0].x=x; point[0].y=y;
						point[1].x=x+d1;point[1].y=y-d1;
						point[2].x=x+d2;point[2].y=y+d2;
						point[3].x=x+d1+d2;point[3].y=y-d1+d2;
						labeling();
					}
				}
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
	solve();
	cout<<ans;
}
