### 17837 새로운 게임2 ★

- 문제를 제대로 이해 못해서 이틀이나 걸렸다. (~~한 문제에 이틀이나 쓰는 남자가 있다?~~)

- 턴종료시 4개일 때가 아니라, **턴내에 4개의 말이 쌓이면 바로 출력**하면 된다.

- 대신 150줄이 넘었던 코드를 리팩토링을 통해 좀 더 효율적으로 구현했다. 하지만 이틀동안 한 문제만 고민하는 과정이 (~~너무너무너무~~)고통스러웠다..

- 참조자(&)와 find함수에 대해 배웠고 이터레이터를 활용하여 push_back, erase, reverse 메서드를 사용했다.

  - 참조자
    - 해당 메모리 주소만을 가르키기 때문에 포인터처럼 이동할 수 있는 개념은 아니다. 변수와 다르게 값을 복사하는 것이 아니라, 해당 주소를 가르키기 때문에 mutable하게 값을 바꿀 수 있다.
  - find(v.begin(),v.end(),value)
    - v의 시작 이터레이터부터 v의 마지막 이터레이터 까지 탐색하며 value값을 찾았을 경우 그 주소의 이터레이터를 반환, 아닐시 v.end()반환
  - reverse(iterater start,iterater end)
    - start부터 end의 이터레이터 범위까지 reverse한다. 

- ```c++
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
  ```

