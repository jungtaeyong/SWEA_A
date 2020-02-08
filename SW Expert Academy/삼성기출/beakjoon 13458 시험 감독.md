### 13458 시험 감독

- 삼성 SW 역량 테스트 기출 문제중 가장 쉬운 문제가 아닐까 생각한다.

- 그리디적인 접근방식으로 풀면 바로 풀리는 문제

- 다만 총 감독관 수는 int형을 초과하기 때문에 long long으로 풀어주는게 관건

- ```c++
  #include <iostream>
  using namespace std;
  int n,b,c,arr[1000001];
  long long cnt=0;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	cin>>b>>c;	
  	for(int i=0;i<n;i++){
  		arr[i]-=b;
  		cnt++;
  		if(arr[i]>0){
  			cnt+=arr[i]/c+!!(arr[i]%c);
  		}
  	}
  	cout<<cnt;
  }
  ```

- 2번째 풀이 (2020-02-08)

  ```c++
  #include <iostream>
  using namespace std;
  int n,a,b,arr[1000001];
  long long cnt=0;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	cin>>a>>b;
  	for(int i=0;i<n;i++){
  		arr[i]-=a;
  		cnt++;
  		if(arr[i]>0){
  			cnt+=arr[i]/b+!!(arr[i]%b);
  		}
  	}
  	cout<<cnt;
  }
  ```

  