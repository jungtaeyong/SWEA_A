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
