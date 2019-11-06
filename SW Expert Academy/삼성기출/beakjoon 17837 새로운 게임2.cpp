#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,arr[13][13],arr_cnt[13][13],ans,cnt;
vector<pair<int,pair<int,int> > > v;
vector<int> move_c[13][13];
typedef struct DIR{
	int r,c;
}DIR;
DIR dir[5]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
bool flag;

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
				continue;
			}
		}
		vector<int>::iterator it;
		vector<int> &cur =move_c[vr][vc];
		vector<int> &next =move_c[mr][mc];
		it=find(cur.begin(),cur.end(),i+1);
		if(arr[mr][mc]==1){
			reverse(it,cur.end());
		}
		vector<int>::iterator s;
		for(s=it;s!=cur.end();++s){
			v[*s-1].second.first=mr;
			v[*s-1].second.second=mc;
			next.push_back(*s);
		}
		cur.erase(it,cur.end());
		flag=chess_count();
		if(flag){
			return;
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
	while(ans<=1000 && !flag){
		solve();
		ans++;
	}
	if(ans>1000){
		cout<<-1;
	}else{
		cout<<ans;
	}
}
