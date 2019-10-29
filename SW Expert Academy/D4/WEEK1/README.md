# WEEK1 SW Expert Academy (D4)



### 1238. contact

문제를 제대로 읽지 않아서 많이 해맸던 문제이다. 하나의 노드 부터 시작해 방문하지 않은 연결된 노드를 탐색하면서 탐색한 **길이가 최대일 경우** 가장 큰 노드의 수를 출력하는 문제. 최대의 길이인지 확인 하기 위해 queue에 현재 길이의 값과 같이 저장해 비교해주었다. 

- ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  #include <cstring> //memset
  using namespace std;
   
  int n,t,maxnum,cnt;
  bool check[101];
  vector<int> v[101];
   
  void bfs(int start){
   
      queue<pair<int, int > > q;
      q.push({start,1});
      check[start]=true;
      while(!q.empty()){
          int x=q.front().first;
          int c=q.front().second;
          q.pop();
          for(int i=0;i<v[x].size();i++){
              int y=v[x][i];
              if(!check[y]){
                  q.push({y,c+1});
                  //길이가 최대일 경우 최대값 갱신
                  if(cnt<c+1){
                      maxnum=y;
                      cnt=c+1;
                  }
                  check[y]=true;
                  bool flag=false;
                  for(int j=0;j<v[y].size();j++){
                      if(!check[v[y][j]]){
                          flag=true;
                      }
                  }
                  //최대의 길이인지 확인한 후 최대값을 비교
                  if(v[y].size()==0||flag==false){
                      if(cnt==c+1){
                          maxnum=max(maxnum,v[x][i]);
                      }
                  }
                   
              }
          }
      }
  }
   
  int main(){
   
      for(int i=0;i<10;i++){
          for(int j=0;j<101;j++){
              v[j].clear();
          }
          memset(check,0,sizeof(check));
          cin>>n>>t;
          maxnum=0;
          cnt=0;
          for(int j=0;j<n/2;j++){
              int temp1,temp2;
              cin>>temp1>>temp2;
              v[temp1].push_back(temp2);  
          }
          bfs(t);
          cout<<"#"<<i+1<<" "<<maxnum<<"\n";
      }
  }
  ```