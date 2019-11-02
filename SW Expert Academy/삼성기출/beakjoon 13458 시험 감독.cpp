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
