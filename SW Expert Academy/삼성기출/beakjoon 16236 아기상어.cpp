#include <iostream>
#include <vector>
#include <queue> 
#include <cstring>
#include <climits>
using namespace std;
typedef struct DIR{
	int r,c;
}DIR;
DIR dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
// ���� ����� �࿭sr,sc �� �ּҰŸ��� �׶��� �࿭��ǥ tr,tc 
int n,arr[20][20],sr,sc,ans,tr,tc,min_cnt;
bool check[20][20],flag;
int s_size=2,s_cnt=0;
//������ �ִ� ����Ⱑ ���Ҵ��� Ȯ �� 
bool chk(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]!=0&&s_size>arr[i][j]){
				return false;
			}
		}
	}
	return true;
}
void bfs(){
	memset(check,0,sizeof(check));
	min_cnt=INT_MAX;
	tr=INT_MAX,tc=INT_MAX;
	queue<pair<int, pair<int, int> > > q;
	q.push({0,{sr,sc}});
	check[sr][sc]=true;
	while(!q.empty()){
		int r=q.front().second.first, c=q.front().second.second;
		int cnt=q.front().first;
		if(arr[r][c]!=0&&arr[r][c]<s_size){
			if(min_cnt>=cnt){
				min_cnt=cnt;
				// �Ÿ��� ���� ��� �������� ����⸦ �Դ´�.
				// ���̰������ �������� ����⸦ �Դ´�.
				if(tr>r){
					tr=r;tc=c;
				}else if(tr==r){
					if(tc>c){
						tc=c;
					}
				}
			}
		}
		q.pop();
		for(int i=0;i<4;i++){
			int mr=r+dir[i].r;
			int mc=c+dir[i].c;
			if(0<=mr&&mr<n&&0<=mc&&mc<n){
				if(!check[mr][mc]&&arr[mr][mc]<=s_size){
					q.push({cnt+1,{mr,mc}});
					check[mr][mc]=true;
				}
			}
		}
	}
	//���� ����� 0���� �ٲٰ� �����ǥ �̵�, ���� Ƚ���� ũ�� �ø��� 
	if(tr==INT_MAX){
		flag=true;
		return;
	}
	arr[tr][tc]=0;
	sr=tr,sc=tc;
	s_cnt++;
	ans+=min_cnt;
	if(s_cnt==s_size){
		s_cnt=0;
		s_size++;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==9){
				sr=i,sc=j;
				arr[i][j]=0;
			}
		}
	}
	while(!flag&&!chk()){
		bfs();
	}
	cout<<ans;
}
