#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r,c,m,fishman,ans;
typedef struct SHARK{
	int r,c,s,d,z,num;
}SHARK;
typedef struct DIR{
	int r,c;
}DIR;
DIR dir[5]={{0,0},{-1,0},{1,0},{0,1},{0,-1}};
vector<SHARK> shark;
vector<int> map[101][101];

bool compare(int a,int b){
	if(shark[a].z>shark[b].z)return true;
	return false;
}

void fishman_move(){
	for(int i=1;i<=r;i++){
		if(map[i][fishman].size()!=0){
			ans+=shark[map[i][fishman][0]].z;
			shark[map[i][fishman][0]].z=0;
			map[i][fishman].clear();
			break;
		}
	}
}

void shark_move(){
	for(int i=0;i<shark.size();i++){
		if(shark[i].z==0) continue;
		map[shark[i].r][shark[i].c].clear();
	}
	for(int i=0;i<shark.size();i++){
		if(shark[i].z==0) continue;
		int row=shark[i].r;
		int col=shark[i].c;
		int direct=shark[i].d;
		int speed=shark[i].s;
		if(direct==1||direct==2){
			int rotate=(r-1)*2;
			if(speed>=rotate)speed=speed%rotate;
			for(int j=0;j<speed;j++){
				int mr=row+dir[direct].r;
				int mc=col+dir[direct].c;
				if(mr<1){
					direct=2;
					mr+=2;
				}
				if(mr>r){
					direct=1;
					mr-=2;
				}
				row=mr;
				col=mc;
			}
		}else{
			int rotate=(c-1)*2;
			if(speed>=rotate)speed=speed%rotate;
			for(int j=0;j<speed;j++){
				int mr=row+dir[direct].r;
				int mc=col+dir[direct].c;
				if(mc<1){
					direct=3;
					mc+=2;
				}
				if(mc>c){
					direct=4;
					mc-=2;
				}
				row=mr;
				col=mc;
			}
		}
		shark[i].r=row;
		shark[i].c=col;
		shark[i].d=direct;
		map[row][col].push_back(i);
	}
}

void shark_check(){
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(map[i][j].size()>1){
				sort(map[i][j].begin(),map[i][j].end(),compare);
				int idx=map[i][j][0];
				for(int k=1;k<map[i][j].size();k++){
					shark[map[i][j][k]].z=0;
					shark[map[i][j][k]].r=-1;
					shark[map[i][j][k]].c=-1;
				}
				map[i][j].clear();
				map[i][j].push_back(shark[idx].num);
			}
		}
	}
}
bool check(){
	for(int i=0;i<shark.size();i++){
		if(shark[i].z!=0)return false;
	}
	return true;
}

int main(){
	cin>>r>>c>>m;
	for(int i=0;i<m;i++){
		SHARK temp_shark;
		cin>>temp_shark.r>>temp_shark.c>>temp_shark.s>>temp_shark.d>>temp_shark.z;
		temp_shark.num=i;
		shark.push_back(temp_shark);
		map[temp_shark.r][temp_shark.c].push_back(i);
	}
	
	for(int i=1;i<=c;i++){
		fishman++;
		if(check())break;
		fishman_move();
		shark_move();
		shark_check();
	}
	cout<<ans;
}
