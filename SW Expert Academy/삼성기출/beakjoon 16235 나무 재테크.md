### 16235 나무 재테크

- 조건에 따라 봄, 여름, 가을, 겨울 조건을 구현하면 되는 문제.

- 핵심은 봄이였는데 iterator를 통해 값을 증가시키려고 `*it++`을 쓰면 에러가 난다. 후위증감연산자의 우선순위가 높기때문이다. 따라서 `(*it)++`을 써야한다.

- iterator를 통해 erase, insert메서드에 익숙해졌고, iterator사용시 뿐만아니라 연산시 연산자의 우선순위를 고려해야 한다는 것을 배웠다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  int n,m,k,arr[11][11],food[11][11],sum,y;
  vector<int> v[11][11];
  vector<int> dtree[11][11];
  typedef struct DIR{
  	int r,c;
  }DIR;
  DIR dir[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
  
  void solve(){
  	// 봄 
  	vector<int>::iterator it;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			sort(v[i][j].begin(),v[i][j].end());
  			for(it=v[i][j].begin();it!=v[i][j].end();it++){
  				if(food[i][j]>=*it){
  					food[i][j]-=*it;
  					(*it)++;
  				}else{
  					dtree[i][j].insert(dtree[i][j].end(),it,v[i][j].end());
  					v[i][j].erase(it,v[i][j].end());
  					break;
  				}
  			}
  		}
  	}
  	//여름
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			for(it=dtree[i][j].begin();it!=dtree[i][j].end();it++){
  				food[i][j]+=(*it)/2;
  			}
  			dtree[i][j].clear();
  		}
  	}
  	//가을
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			for(int k=0;k<v[i][j].size();k++){
  				if(v[i][j][k]%5==0){
  					for(int k=0;k<8;k++){
  						int mr=i+dir[k].r;
  						int mc=j+dir[k].c;
  						if(1<=mr&&mr<=n&&1<=mc&&mc<=n){
  							v[mr][mc].push_back(1);
  						}
  					}
  				}
  			}
  		}
  	}
  	//겨울
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			food[i][j]+=arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			sum+=v[i][j].size();
  		}
  	}
  	y++;
  }
  
  int main(){
  	cin>>n>>m>>k;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			food[i][j]=5;
  		}
  	}
  	for(int i=0;i<m;i++){
  		int temp_x,temp_y,temp_year;
  		cin>>temp_x>>temp_y>>temp_year;
  		v[temp_x][temp_y].push_back(temp_year);
  	}
  	while(y!=k){
  		sum=0;
  		solve();
  	}
  	cout<<sum;
  }
  ```

