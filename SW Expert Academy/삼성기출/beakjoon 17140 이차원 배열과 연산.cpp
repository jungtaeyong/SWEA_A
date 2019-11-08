#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int r,c,k,ans,rownum=3,colnum=3;
int map[101][101];
int chk[101];
bool check(){
	if(map[r][c]==k){
		return true;
	}
	return false;
}
void r_cal(){
	int maxsize=0;
	for(int i=1;i<=rownum;i++){
		vector<pair <int, int> > v;
		memset(chk,0,sizeof(chk));
		for(int j=1;j<=colnum;j++){
			chk[map[i][j]]++;
		}
		for(int j=1;j<=colnum;j++){
			map[i][j]=0;
		}
		for(int j=1;j<=100;j++){
			if(chk[j]!=0){
				v.push_back({chk[j],j});
			}
		}
		sort(v.begin(),v.end());
		int idx=0;
		for(int j=0;j<v.size();j++){
			map[i][++idx]=v[j].second;
			map[i][++idx]=v[j].first;
		}
		maxsize=max(maxsize,idx);
	}
	colnum=maxsize;
}
void c_cal(){
	int maxsize=0;
	for(int i=1;i<=colnum;i++){
		vector<pair <int, int> > v;
		memset(chk,0,sizeof(chk));
		for(int j=1;j<=rownum;j++){
			chk[map[j][i]]++;
		}
		for(int j=1;j<=rownum;j++){
			map[j][i]=0;
		}
		for(int j=1;j<=100;j++){
			if(chk[j]!=0){
				v.push_back({chk[j],j});
			}
		}
		sort(v.begin(),v.end());
		int idx=0;
		for(int j=0;j<v.size();j++){
			map[++idx][i]=v[j].second;
			map[++idx][i]=v[j].first;
		}
		maxsize=max(maxsize,idx);
	}
	rownum=maxsize;
}
void solve(){
	if(rownum>=colnum){
		r_cal();
	}else{
		c_cal();
	}
}
int main(){
	cin>>r>>c>>k;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>map[i][j];
		}
	}
	while(ans<=100&&!check()){
		solve();
		ans++;
	}
	if(ans==101){
		cout<<-1;
	}else{
		cout<<ans;
	}
}
