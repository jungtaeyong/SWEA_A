#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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
