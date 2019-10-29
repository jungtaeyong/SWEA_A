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

