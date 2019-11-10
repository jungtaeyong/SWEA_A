#include <iostream>
#include <vector>

using namespace std;
int n,m,t,ans,cnt;
vector<pair<int,int> > v[51];
vector<int> t_v[51];
bool check;
void solve(){
	int x=t_v[cnt][0],d=t_v[cnt][1],k=t_v[cnt][2];
	k=k%m;
	int count=k%m;
	for(int i=x;i<=n;i+=x){
		
		if(d==1){
			count=m-k;
		}
		int temp[m];
		for(int j=0;j<v[i].size();j++){
			temp[j]=v[i][j].second;
		}
		for(int j=0;j<v[i].size();j++){
			v[i][j].second=temp[(j+m-count)%m];
		}
	}

	check=false;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(j==v[i].size()-1){
				if(v[i][j].second!=0&&v[i][j].second==v[i][0].second){
					check=true;
					v[i][j].first=1;
					v[i][0].first=1;
				}
			}else{
				if(v[i][j].second!=0&&v[i][j].second==v[i][j+1].second){
					check=true;
					v[i][j].first=1;
					v[i][j+1].first=1;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j].second!=0&&v[i][j].second==v[i+1][j].second){
				check=true;
				v[i][j].first=1;
				v[i+1][j].first=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j].first==1){
				v[i][j].second=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			v[i][j].first=0;
		}
	}
	
	if(!check){
		int num=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				if(v[i][j].second!=0){
					num++;
					sum+=v[i][j].second;
				}
			}
		}
		double avg=(double)sum/num;
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				if(v[i][j].second!=0){
					if(avg>v[i][j].second){
						v[i][j].second++;
					}else if(avg<v[i][j].second){
						v[i][j].second--;
					}
				}
			}
		}
	}
	
}

int main(){
	
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			int mm;
			cin>>mm;
			v[i].push_back({0,mm});
		}
	}
	for(int i=1;i<=t;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		t_v[i].push_back(t1);
		t_v[i].push_back(t2);
		t_v[i].push_back(t3);
	}
	
	while(cnt!=t){
		cnt++;
		solve();
	}

	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			ans+=v[i][j].second;
		}
	}
	cout<<ans;
}

