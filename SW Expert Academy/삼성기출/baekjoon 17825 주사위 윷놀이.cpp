#include <iostream>
#include <vector>
using namespace std;

int piece[5],ans,board[33][2],score[33];
vector<int> v;
bool chk[33];

void dfs(int depth,int sum){
	if(depth==10){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<4;i++){
		int cnt=v[depth];
		int before=piece[i];
		int after=piece[i];
		
		if(after==5||after==10||after==15){
			after=board[after][1];
			cnt--;
		}
		
		while(cnt--){
			after=board[after][0];
		}
		
		if(after!=21&&chk[after])continue;
		
		piece[i]=after;
		chk[before]=false;
		chk[after]=true;
		
		dfs(depth+1,sum+score[after]);
		
		piece[i]=before;
		chk[before]=true;
		chk[after]=false;	
	}
	
}

int main(){
	for(int i=0;i<10;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<=24;i++){
		board[i][0]=i+1;
	}
	board[21][0]=21;
    board[25][0]=31;
    board[26][0]=25;
    board[27][0]=26;
    board[28][0]=27;
    board[29][0]=30;
    board[30][0]=25;
    board[31][0]=32;
    board[32][0]=20;
    
    board[5][1]=22;
    board[10][1]=29;
   	board[15][1]=28;
	for(int i=1;i<=20;i++) {
		score[i]=i*2;
	}
    for(int i=22;i<=24;i++){
    	score[i]=13+(i-22)*3;
	}
    for(int i=26;i<=28;i++){
    	score[i]=i;
	}
	score[25]=25;
    score[31]=30;
    score[32]=35;
    score[29]=22;
    score[30]=24;
    dfs(0,0);
    cout<<ans;
}
