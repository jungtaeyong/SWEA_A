### 17822 원판돌리기

- 주어진 조건에 따라 원판을 돌리며 인접한 수를 제거 혹은 평균을 구해 값을 조절하여 총 점수를 구하는 문제.

- 주어진 조건에 맞게 구현하면 되지만 구현에 있어 몇가지 난관이 있었다.

  - 배열로 값을 넣을 경우 원판을 1번 돌릴때마다 방향에 따라 배열이 1칸씩 밀리거나 당겨진다. 어떻게 해결해야 할까?

    - N,M,T 값이 50으로 작은편이므로 수를 shift 할 때 한번씩 밀어줘도 되지만, 된다고 하더라도 매우 비효율적이므로 따로 연산한다. 그렇다면 어떻게 연산할 수 있을까? 잘 생각해보면 어떤 원판을 M번만큼 돌리면 그 원판은 돌리기 전과 같은 상태가된다. 이건 시계방향으로 돌려도, 반시계방향으로 돌려도 마찬가지이다. 당연하게도 원이기 때문에 제자리로 돌아오기 떄문이다. (~~왜 이 당연한걸 나는15분만에 생각했을까...~~) 따라서 돌리는 횟수를 K라 했을때, K%M번 만큼만 계산해주면된다.

      

  - 인접할 경우 바로 0으로 지워주면 그 다음 원판이 인접한지 알 수없다. (이미 0으로 바뀌었기때문) 어떻게 해결 해야 할까?

    - 벡터를 pair로 선언해 first엔 지워야할 배열인지 아닌지 표시해주고, second엔 해당 점수를 저장했다.
    - 인접할 경우 first를 1로 바꾸어 표시만 해주고 for문을 다 돌고 난 이후에 최종적으로 해당 점수를 0으로 바꿔준다.

- 보통은 모듈화하여 조건별로 나누어 풀지만 이 문제는 빠르게 풀 수 있다고 판단했지만 결국 시간도 오래걸렸고 가독성 낮은 코드를 짜버렸다. 난이도를 따지지말고 항상 모듈화하여 푸는 습관을 들여야겠다.

- ```c++
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
  ```