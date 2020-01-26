#include <iostream>
#include <cmath>
using namespace std;
int n,m;
int main(){

    for(int t=1;t<=10;t++){
    	int a;
		cin>>a;
   		cin>>n>>m;
    	cout<<"#"<<a<<" "<<(int)pow(n,m)<<"\n";
    }
}
