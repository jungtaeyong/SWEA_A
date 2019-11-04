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
			cout<<move_c[i][j].size()<<" ";
			for(int k=0;k<move_c[i][j].size();k++){
				//cout<<move_c[i][j][k]<<" ";
			}
			//cout<<"\n";
			if(move_c[i][j].size()>=4){
				return true;
			}
		}
		cout<<"\n";
	}
	cout<<"\n";
	return false;
}

void solve(){
	for(int i=0;i<v.size();i++){
		int vr=v[i].second.first,vc=v[i].second.second,vdir=v[i].first;
		int mr=vr+dir[vdir].r,mc=vc+dir[vdir].c;
		//cout<<"mr: "<<mr<<" mc: "<<mc<<"\n";
		// BLUE 
		if(mr<1||n<mr||mc<1||n<mc||arr[mr][mc]==2){
			//방향전환
			if(vdir%2==0){
				vdir--;
			}else{
				vdir++;
			}
			mr=vr+dir[vdir].r,mc=vc+dir[vdir].c;
			if(mr<1||n<mr||mc<1||n<mc||arr[mr][mc]==2){
				v[i].first=vdir;
			}else{
				//먼저 move_c확인
				vector<int>::iterator it;
				for(it=move_c[vr][vc].begin();it!=move_c[vr][vc].end();it++){
					if(*it==i+1){
						//vector1.insert(vector1.end(),vector2.begin(),vector2.end())
						move_c[mr][mc].insert(move_c[mr][mc].end(),it,move_c[vr][vc].end());
						move_c[vr][vc].erase(it,move_c[vr][vc].end());
//						cout<<"insert\n";
//						for(int k=0; k<move_c[mr][mc].size(); k++) {
//							cout<<move_c[mr][mc][k]<<" ";
//						}
//						cout<<"\n";
//						cout<<"erase\n";
//						for(int l=0; l<move_c[vr][vc].size(); l++) {
//							cout<<move_c[vr][vc][l]<<" ";
//						}
//						cout<<"\n";
						break;
					}
				}
				v[i].second.first=mr,v[i].second.second=mc,v[i].first=vdir;
			}
		}else if(arr[mr][mc]==1){
			vector<int>::iterator it;
			for(it=move_c[vr][vc].begin();it!=move_c[vr][vc].end();it++){
				if(*it==i+1){
					//reverse(it,move_c[vr][vc].end());
					move_c[mr][mc].insert(move_c[mr][mc].end(),it,move_c[vr][vc].end());
					move_c[vr][vc].erase(it,move_c[vr][vc].end());
					break;
				}
			}
			for(it=move_c[mr][mc].begin();it!=move_c[mr][mc].end();it++){
				if(*it==i+1){
					reverse(it,move_c[mr][mc].end());
				}
			}
			v[i].second.first=mr,v[i].second.second=mc,v[i].first=vdir;
		}
		else{
			vector<int>::iterator it;
			for(it=move_c[vr][vc].begin();it!=move_c[vr][vc].end();it++){
				if(*it==i+1){
					move_c[mr][mc].insert(move_c[mr][mc].end(),it,move_c[vr][vc].end());
					move_c[vr][vc].erase(it,move_c[vr][vc].end());
//					cout<<"moved: ";
//					cout<<mr<<" "<<mc<<"\n";
//					cout<<"original: ";
//					cout<<vr<<" "<<vc<<"\n";
//					cout<<"insert\n";
//					for(int k=0; k<move_c[mr][mc].size(); k++) {
//						cout<<move_c[mr][mc][k]<<" ";
//					}
//					cout<<"\n";
//					cout<<"erase\n";
//					for(int l=0; l<move_c[vr][vc].size(); l++) {
//						cout<<move_c[vr][vc][l]<<" ";
//					}
//					cout<<"\n";
					break;
				}
			}
			v[i].second.first=mr,v[i].second.second=mc,v[i].first=vdir;
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
