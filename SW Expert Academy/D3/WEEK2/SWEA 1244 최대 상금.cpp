#include <iostream>
#include <algorithm>
using namespace std;
 
int n,t,cnt,ans;
string str;
string maxstr;
bool check[6];

void dfs(int depth, int count){
	
	if(count==n){
		if(maxstr<str){
			maxstr=str;
		}
		return;
	}

	for(int i=depth;i<str.length();i++){
		for(int j=i+1;j<str.length();j++){
			if(str[i]<=str[j]){
				char temp;
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
				dfs(i,count+1);
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
}

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	for(int k=0;k<t;k++){
		cnt=0;
		maxstr="";
		ans=0;
		cin>>str>>n;
		dfs(0,0);
		cout<<"#"<<k+1<<" "<<ans<<"\n";	
	}
	
} 
