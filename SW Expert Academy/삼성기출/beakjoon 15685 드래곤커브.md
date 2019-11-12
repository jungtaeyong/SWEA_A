### 15685 드래곤커브 ★

- 좌표의 나열만으로 규칙을 찾으려해서 못풀었던 문제.
- 규칙은 방향으로 찾을 수 있고, 점의 수는 2를 등비로 가지는 등비수열이다.

```
0 세대 - 0
1 세대 - 0 1
2 세대 - 0 1 2 1
3 세대 - 0 1 2 1 2 3 2 1
4 세대 - 0 1 2 1 2 3 2 1 2 3 0 3 2 3 2 1
```

- ```c++
  #include <iostream>
  #include <math.h>
  using namespace std;
  
  int n,gener[4][1024],ans;
  bool arr[101][101];
  
  int main(){
  	// 각 방향의 세대 초기값 ex) 0방향의 0세대의 방향은0 
  	gener[0][0]=0;
  	gener[1][0]=1;
  	gener[2][0]=2;
  	gener[3][0]=3;
      // 범위가 0이상 100이하이기 떄문에 10세대까지만 구해도 된다.
  	for(int k=0;k<4;k++){
  		for(int i=1;i<=10;i++){
  			int start=pow(2,i-1);
  			int end=pow(2,i);
  			for(int j=start,l=1;j<end;j++,l+=2){
  				gener[k][j]=gener[k][j-l]+1==4? 0 : gener[k][j-l]+1;
  			}
  		}
  	}
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int x,y,d,g;
  		cin>>x>>y>>d>>g;
  		int end=pow(2,g);
  		int curx=x;
  		int cury=y;
  		//행열이기 떄문에 x는 열, y는 행으로 보아야한다.
  		arr[cury][curx]=true;
  		for(int j=0;j<end;j++){
              //방향에 따른 좌표값 처리
  			if(gener[d][j]==0){
  				curx+=1;
  			}else if(gener[d][j]==1){
  				cury-=1;
  			}else if(gener[d][j]==2){
  				curx-=1;
  			}else{
  				cury+=1;
  			}
  			arr[cury][curx]=true;
  		}
  	}
      // 완전탐색으로 탐색한다.
  	for(int i=0;i<100;i++){
  		for(int j=0;j<100;j++){
  			if(arr[i][j]&&arr[i][j+1]&&arr[i+1][j]&&arr[i+1][j+1]){
  				ans++;
  			}
  		}
  	}
  	cout<<ans;
  }
  ```

- #### 참고 출처: [마이구미의 HelloWorld](https://mygumi.tistory.com/336)

  

