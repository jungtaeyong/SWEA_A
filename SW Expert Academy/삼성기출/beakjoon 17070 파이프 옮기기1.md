### 17070 파이프 옮기기1

- 주어진 조건에 따라 가지를 치며 (벽이 있는 경우) 백트래킹하는 문제. 난이도가 높진 않았다.

- 문제에서 색으로 칠해져있는 곳은 0이어야 하기 때문에, 대각선일 경우 3칸이전부 0이어야한다.

- ```C++
  #include <iostream>
  using namespace std;
  int n,arr[17][17],ans,now[2][2];
  int r,c;
  void dfs(int r1,int c1,int r2,int c2){
  	if(r2==n&&c2==n){
  		ans++;
  		return;
  	}
  	//가로 
  	if(r1==r2&&c1+1==c2){
  		if(c2+1<=n&&arr[r2][c2+1]!=1){
  			dfs(r2,c2,r2,c2+1);
  		}
  		if(r2+1<=n&&c2+1<=n&&arr[r2+1][c2+1]!=1&&arr[r2+1][c2]!=1
  		&&arr[r2][c2+1]!=1){
  			dfs(r2,c2,r2+1,c2+1);
  		}
  	}
  	//세로
  	if(r1+1==r2&&c1==c2){
  		if(r2+1<=n&&arr[r2+1][c2]!=1){
  			dfs(r2,c2,r2+1,c2);
  		}
  		if(r2+1<=n&&c2+1<=n&&arr[r2+1][c2+1]!=1
  		&&arr[r2+1][c2]!=1&&arr[r2][c2+1]!=1){
  			dfs(r2,c2,r2+1,c2+1);
  		}	
  	} 
  	//대각선 
  	if(r1+1==r2&&c1+1==c2){
  		if(c2+1<=n&&arr[r2][c2+1]!=1){
  			dfs(r2,c2,r2,c2+1);
  		}
  		if(r2+1<=n&&arr[r2+1][c2]!=1){
  			dfs(r2,c2,r2+1,c2);
  		}
  		if(r2+1<=n&&c2+1<=n&&arr[r2+1][c2+1]!=1
  		&&arr[r2+1][c2]!=1&&arr[r2][c2+1]!=1){
  			dfs(r2,c2,r2+1,c2+1);
  		}
  	}
  }
  int main(){
  	cin>>n;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	dfs(1,1,1,2);
  	cout<<ans;
  }
  ```