#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct GEAR{
	string str;
	int rd;	
};
vector<GEAR> v(5);
string gear[5];
int k,ans;
void solve(int gnum, int d){
	int ngnum1=gnum;
	int ngnum2=gnum;
	int rgnum=gnum+1;
	int lgnum=gnum-1;
	int check[5];
	memset(check,0,sizeof(check));
	check[gnum]=d;
	while(rgnum<=4){
		int l=(v[rgnum].rd+4)%8;
		int nr=v[ngnum1].rd;
		if(v[ngnum1].str[nr]==v[rgnum].str[l]){
			break;
		}else{
			check[rgnum]=check[ngnum1]*-1;
		}
		ngnum1++;
		rgnum++;
	}
	while(lgnum>=1){
		int r=v[lgnum].rd;
		int nr=v[ngnum2].rd;
		int nl=(nr+4)%8;
		if(v[ngnum2].str[nl]==v[lgnum].str[r]){
			break;
		}else{
			check[lgnum]=check[ngnum2]*-1;
		}
		ngnum2--;
		lgnum--;
	}
	for(int i=1;i<=4;i++){
		if(check[i]==1){
			v[i].rd=(v[i].rd+7)%8;	
		}else if(check[i]==-1){
		 	v[i].rd=(v[i].rd+1)%8;
		}
	}
}
int main(){
	cin>>gear[1]>>gear[2]>>gear[3]>>gear[4]>>k;
	for(int i=1;i<=4;i++){
		v[i].str=gear[i];
		v[i].rd=2;
	}
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		solve(a,b);
	}
	for(int i=1;i<=4;i++){
		if(v[i].str[(v[i].rd+6)%8]=='1'){
			ans+=1<<(i-1);
		}
	}
	cout<<ans;
}
