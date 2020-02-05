#include <iostream>
using namespace std;

int t,n,arr[7][4][4];
char color[7]={'0','o','w','r','y','g','b'};

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=1;i<=6;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					arr[i][j][k]=i;
				}
			}
		}
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			int temp[7][4];
			int temp2[10];
			int cnt=1; 
			if(str=="L-"){
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						temp[i][j]=arr[i][j][1];
					}
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						if(i==4){
							arr[i][j][1]=temp[1][j];
						}else{
							arr[i][j][1]=temp[i+1][j];
						}
					}
				}
				for(int i=3;i>=1;i--){
					for(int j=1;j<=3;j++){
						temp2[cnt++]=arr[5][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[5][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="L+"){
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						temp[i][j]=arr[i][j][1];
					}
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						if(i==1){
							arr[i][j][1]=temp[4][j];
						}else{
							arr[i][j][1]=temp[i-1][j];
						}
					}
				}
				for(int i=1;i<=3;i++){
					for(int j=3;j>=1;j--){
						temp2[cnt++]=arr[5][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[5][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="R+"){
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						temp[i][j]=arr[i][j][3];
					}
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						if(i==4){
							arr[i][j][3]=temp[1][j];
						}else{
							arr[i][j][3]=temp[i+1][j];
						}
					}
				}
				for(int i=1;i<=3;i++){
					for(int j=3;j>=1;j--){
						temp2[cnt++]=arr[6][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[6][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="R-"){
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						temp[i][j]=arr[i][j][3];
					}
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=3;j++){
						if(i==1){
							arr[i][j][3]=temp[4][j];
						}else{
							arr[i][j][3]=temp[i-1][j];
						}
					}
				}
				for(int i=3;i>=1;i--){
					for(int j=1;j<=3;j++){
						temp2[cnt++]=arr[6][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[6][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="B+"){
				for(int i=1;i<=3;i++){
					temp[2][i]=arr[2][1][i];
					temp[5][i]=arr[5][1][i];
					temp[6][i]=arr[6][1][i];
					temp[4][i]=arr[4][3][i];
				}
				for(int i=1;i<=3;i++){
					arr[2][1][i]=temp[6][i];
					arr[5][1][i]=temp[2][i];
				}
				arr[6][1][1]=temp[4][3];
				arr[6][1][2]=temp[4][2];
				arr[6][1][3]=temp[4][1];
				arr[4][3][1]=temp[5][3];
				arr[4][3][2]=temp[5][2];
				arr[4][3][3]=temp[5][1];
				for(int i=1;i<=3;i++){
					for(int j=3;j>=1;j--){
						temp2[cnt++]=arr[1][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[1][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="B-"){
				for(int i=1;i<=3;i++){
					temp[2][i]=arr[2][1][i];
					temp[5][i]=arr[5][1][i];
					temp[6][i]=arr[6][1][i];
					temp[4][i]=arr[4][3][i];
				}
				for(int i=1;i<=3;i++){
					arr[2][1][i]=temp[5][i];
					arr[6][1][i]=temp[2][i];
				}
				arr[5][1][1]=temp[4][3];
				arr[5][1][2]=temp[4][2];
				arr[5][1][3]=temp[4][1];
				arr[4][3][1]=temp[6][3];
				arr[4][3][2]=temp[6][2];
				arr[4][3][3]=temp[6][1];
				for(int i=3;i>=1;i--){
					for(int j=1;j<=3;j++){
						temp2[cnt++]=arr[1][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[1][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="F-"){
				for(int i=1;i<=3;i++){
					temp[2][i]=arr[2][3][i];
					temp[5][i]=arr[5][3][i];
					temp[6][i]=arr[6][3][i];
					temp[4][i]=arr[4][1][i];
				}
				for(int i=1;i<=3;i++){
					arr[2][3][i]=temp[6][i];
					arr[5][3][i]=temp[2][i];
				}
				arr[6][3][1]=temp[4][3];
				arr[6][3][2]=temp[4][2];
				arr[6][3][3]=temp[4][1];
				arr[4][1][1]=temp[5][3];
				arr[4][1][2]=temp[5][2];
				arr[4][1][3]=temp[5][1];
				for(int i=3;i>=1;i--){
					for(int j=1;j<=3;j++){
						temp2[cnt++]=arr[3][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[3][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="F+"){
				for(int i=1;i<=3;i++){
					temp[2][i]=arr[2][3][i];
					temp[5][i]=arr[5][3][i];
					temp[6][i]=arr[6][3][i];
					temp[4][i]=arr[4][1][i];
				}
				for(int i=1;i<=3;i++){
					arr[2][3][i]=temp[5][i];
					arr[6][3][i]=temp[2][i];
				}
				arr[5][3][1]=temp[4][3];
				arr[5][3][2]=temp[4][2];
				arr[5][3][3]=temp[4][1];
				arr[4][1][1]=temp[6][3];
				arr[4][1][2]=temp[6][2];
				arr[4][1][3]=temp[6][1];
				for(int i=1;i<=3;i++){
					for(int j=3;j>=1;j--){
						temp2[cnt++]=arr[3][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[3][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="U+"){
				for(int i=1;i<=3;i++){
					temp[1][i]=arr[1][3][i];
					temp[5][i]=arr[5][i][3];
					temp[3][i]=arr[3][1][i];
					temp[6][i]=arr[6][i][1];
				}
				for(int i=1;i<=3;i++){
					arr[5][i][3]=temp[3][i];
					arr[6][i][1]=temp[1][i];
				}
				arr[1][3][1]=temp[5][3];
				arr[1][3][2]=temp[5][2];
				arr[1][3][3]=temp[5][1];
				arr[3][1][1]=temp[6][3];
				arr[3][1][2]=temp[6][2];
				arr[3][1][3]=temp[6][1];
				
				for(int i=1;i<=3;i++){
					for(int j=3;j>=1;j--){
						temp2[cnt++]=arr[2][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[2][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="U-"){
				for(int i=1;i<=3;i++){
					temp[1][i]=arr[1][3][i];
					temp[5][i]=arr[5][i][3];
					temp[3][i]=arr[3][1][i];
					temp[6][i]=arr[6][i][1];
				}
				for(int i=1;i<=3;i++){
					arr[1][3][i]=temp[6][i];
					arr[3][1][i]=temp[5][i];
				}
				arr[5][1][3]=temp[1][3];
				arr[5][2][3]=temp[1][2];
				arr[5][3][3]=temp[1][1];
				arr[6][1][1]=temp[3][3];
				arr[6][2][1]=temp[3][2];
				arr[6][3][1]=temp[3][1];
				
				for(int i=3;i>=1;i--){
					for(int j=1;j<=3;j++){
						temp2[cnt++]=arr[2][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[2][i][j]=temp2[cnt++];
					}
				}
			}else if(str=="D+"){
				for(int i=1;i<=3;i++){
					temp[1][i]=arr[1][1][i];
					temp[5][i]=arr[5][i][1];
					temp[3][i]=arr[3][3][i];
					temp[6][i]=arr[6][i][3];
				}
				for(int i=1;i<=3;i++){
					arr[1][1][i]=temp[6][i];
					arr[3][3][i]=temp[5][i];
				}
				arr[5][1][1]=temp[1][3];
				arr[5][2][1]=temp[1][2];
				arr[5][3][1]=temp[1][1];
				arr[6][1][3]=temp[3][3];
				arr[6][2][3]=temp[3][2];
				arr[6][3][3]=temp[3][1];
				
				for(int i=1;i<=3;i++){
					for(int j=3;j>=1;j--){
						temp2[cnt++]=arr[4][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[4][i][j]=temp2[cnt++];
					}
				}
				
			}else if(str=="D-"){
				for(int i=1;i<=3;i++){
					temp[1][i]=arr[1][1][i];
					temp[5][i]=arr[5][i][1];
					temp[3][i]=arr[3][3][i];
					temp[6][i]=arr[6][i][3];
				}
				for(int i=1;i<=3;i++){
					arr[5][i][1]=temp[3][i];
					arr[6][i][3]=temp[1][i];
				}
				arr[1][1][1]=temp[5][3];
				arr[1][1][2]=temp[5][2];
				arr[1][1][3]=temp[5][1];
				arr[3][3][1]=temp[6][3];
				arr[3][3][2]=temp[6][2];
				arr[3][3][3]=temp[6][1];
				
				for(int i=3;i>=1;i--){
					for(int j=1;j<=3;j++){
						temp2[cnt++]=arr[4][j][i];
					}
				}
				cnt=1;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						arr[4][i][j]=temp2[cnt++];
					}
				}
			}		
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				cout<<color[arr[2][i][j]];
			}
			cout<<"\n";
		}		
	}
	
}
