#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int arr[100];
pair<int,int> minpair=make_pair(-1,INT_MAX);
pair<int,int> maxpair=make_pair(-1,0);
int main(){
	for(int t=0;t<10;t++){
		int n;
		cin>>n;
		for(int j=0;j<100;j++){
			cin>>arr[j];
		}
		for(int i=0;i<n;i++){
			sort(arr,arr+100);
			arr[0]++;
			arr[99]--;
		}
		sort(arr,arr+100);
		cout<<"#"<<t+1<<" "<<arr[99]-arr[0]<<"\n";
	}	
}
