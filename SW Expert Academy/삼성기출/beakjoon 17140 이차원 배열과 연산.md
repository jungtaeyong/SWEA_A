### 17140 이차원 배열과 연산

- 행과 열의 연산을 통해 조건을 판별해 횟수를 출력하는 문제.
- 열 연산에서 복잡해질 것 같았는데 의외로 행연산과 거의 똑같다.
- 핵심은 해당 열또는 행에서의 수와 그 수에 따른 갯수를 pair로 저장하는 것
  - 처음엔 map을 떠올렸는데 sort하는 과정이 필요한데 map으로는 복잡할 것 같아서 vector로 구현했다.
  - <수,갯수>로 저장하지않고 <갯수,수>로 저장하면 별도로 sort함수를 구현할 필요가 없다.

- 행연산과 열연산시 인덱스를 주의하자. 그부분 외엔 어렵지 않게 해결할 수 있었다.

- ```c++
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
  ```

  