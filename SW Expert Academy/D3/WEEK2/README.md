# WEEK 2 SW Expert Academy (D3)

### 1244 최대 상금

- 얼핏보면 이중탐색을 이용한 그리디 문제인것 처럼 보인다. 그래서 많이 헤맨 문제.
  - 그리디적인 접근방식을 했을때 32888 2가 반례이다.

- 따라서 그리디적인 접근방식으론 문제를 풀 수 없다. 정수는 최대 6자리이기 때문에 백트래킹(DFS)를 이용해 문제를 풀었다.

- ```C++
  #include <iostream>
  using namespace std;
  int n,t,cnt,ans;
  string str;
  string maxstr;
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
  ```



