# WEEK1 SW Expert Academy (D3)

### 2806 N-Queen

- N x N의 체스판에 N개의 퀸을 놓았을 때 서로 공격할 수 없도록 배치하는 경로의 수를 구하는 문제

- 백트래킹의 대표적인 문제로 같은 행, 같은 열, 대각선 상에 위치 한다면 가지를 처내면서 해당 깊이 N을 만족할 때 ans값을 ++ 해준다.

- 핵심은 대각선의 판별인데, 결국 대각선이란 뜻은 기울기가 1이란 뜻이기 때문에 두 점의 x좌표와 y좌표의 차이의 절대값이 같은지 확인하는 것으로 판별이 가능하다.

- ```c++
  #include <iostream>
  #include <stdlib.h>
  using namespace std;
  int n,row[15],ans,t;
  bool check(int now){
      for(int i=0;i<now;i++){
          //abs() : 절대값 구하는 함수 
          if(row[i]==row[now] || abs(row[i]-row[now])==abs(i-now)){
              return false;
          }
      }
      return true;
  }
  void queen(int now){
      if(now==n){
          ans++;
      }else{
          for(int i=0;i<n;i++){
              row[now]=i;
              if(check(now)){
                  queen(now+1);   
              }
          }
      }
  }
  
  int main(){
      cin>>t;
      for(int i=0;i<t;i++){
          for(int j=0;j<15;j++){
              row[j]=0;
          }
          cin>>n;
          queen(0);
          cout<<"#"<<i+1<<" "<<ans<<"\n";
          ans=0;
      }
  }
  ```



### 1206 View

- 각 빌딩의 조망권은 양옆으로 2의 거리 내에서 빌딩이 존재하지 않을 때 확보할 수 있다. 조망권의 빌딩 층 수의 합을 구하는 문제

- Input값이 배열이 아닌 해당 빌딩 층의 수로 제공한다. 따라서 배열로 생각하기 보다 조망권의 빌딩 층 수를 어떻게 쉽게 구할 지 생각해봤다.

- 해당 빌딩이 가장 높아야하며, 양옆으로 2의 거리 내에서의 빌딩의 제일 큰 값과의 차이를 구하면 된다.

- ```c++
  #include <iostream>
  #include <climits>
  using namespace std;
  int arr[1004],n,ans;
  int main(){
  	for(int t=0;t<10;t++){
  		cin>>n;
  		ans=0;
  		for(int i=2;i<n+2;i++){
  			cin>>arr[i];
  		}
  		arr[n+2]=0;
  		arr[n+3]=0;
  		for(int i=2;i<n+2;i++){
  			int minnum=INT_MAX;
  			minnum=min(minnum,arr[i]-arr[i-1]);
  			minnum=min(minnum,arr[i]-arr[i-2]);
  			minnum=min(minnum,arr[i]-arr[i+1]);
  			minnum=min(minnum,arr[i]-arr[i+2]);
  			if(minnum>0){
  				ans+=minnum;
  			}
  		}
  		cout<<"#"<<t+1<<" "<<ans<<"\n";
  	}
  }
  
  ```



### 느낀점

- D3 난이도는 전반적으로 문제의 난이도가 어렵지 않은 편이였다. 이번 문제는 백트래킹과 간단한 수학문제였는데, 기본적인 개념정도만 알고 있으면 어렵지 않게 풀 수 있는 문제였다. A형 시험에 이런 간단한 문제가 나올 것 같지는 않지만 개념을 잡기엔 좋은 예시문제 였다는 생각이 들었다.