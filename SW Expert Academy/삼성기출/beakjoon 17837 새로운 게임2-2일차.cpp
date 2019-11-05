#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,arr[13][13],arr_cnt[13][13],ans,cnt;
vector<pair<int,pair<int,int> > > v;
vector<int> move_c[12][12];
typedef struct DIR{
	int r,c;
}DIR;
DIR dir[5]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
bool chess_count(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(move_c[i][j].size()>=4){
				return true;
			}
		}
	}
	return false;
}


void solve(){
	for(int i=0;i<v.size();i++){
		int vr=v[i].second.first,vc=v[i].second.second,vdir=v[i].first;
		int mr=vr+dir[vdir].r,mc=vc+dir[vdir].c;
		if(mr<1||n<mr||mc<1||n<mc||arr[mr][mc]==2){
			if(vdir%2==0){
				vdir--;
			}else{
				vdir++;
			}
			v[i].first=vdir;
			mr=vr+dir[vdir].r,mc=vc+dir[vdir].c;
			if(mr<1||n<mr||mc<1||n<mc||arr[mr][mc]==2){
				return;
			}
		}
		vector<int>::iterator it;
		if(arr[mr][mc]==1){
			for(it=move_c[vr][vc].begin();it!=move_c[vr][vc].end();it++){
				if(*it==i+1){
					reverse(it,move_c[vr][vc].end());
					break;
				}
			}
		}
		for(it=move_c[vr][vc].begin();it!=move_c[vr][vc].end();it++){
			if(*it==i+1){
				move_c[mr][mc].insert(move_c[mr][mc].end(),it,move_c[vr][vc].end());
				move_c[vr][vc].erase(it,move_c[vr][vc].end());
				break;
			}
		}
		for(it;it!=move_c[mr][mc].end();it++){
			v[*it-1].second.first=mr,v[*it-1].second.second=mc;
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=k;i++){ 
		int temp_r,temp_c,temp_dir;
		cin>>temp_r>>temp_c>>temp_dir;
		v.push_back({temp_dir,{temp_r,temp_c}});
		move_c[temp_r][temp_c].push_back(i);
	}

	bool chk = chess_count();
	while(ans<=10 && !chk){
		solve();
		chk = chess_count();
		ans++;
	}
	if(ans>1000){
		cout<<-1;
	}else{
		cout<<ans;
	}
	
}
