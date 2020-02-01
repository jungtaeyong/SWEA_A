#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans, x,y,z, N,M,K, a[11][11], land[11][11];
vector<int> dead[11][11], tree[11][11];
int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};

void spring() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(!tree[i][j].empty()) {
        sort(tree[i][j].begin(), tree[i][j].end());
        for(vector<int>::iterator it = tree[i][j].begin(); it != tree[i][j].end(); it++) {
          if(land[i][j] >= *it) {
            land[i][j] -= *it;
            (*it)++;
          } else {
            dead[i][j].insert(dead[i][j].end(), it, tree[i][j].end());
            tree[i][j].erase(it, tree[i][j].end());
            break;
          }
        }
      }
    }
  }
}

void summer() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(!dead[i][j].empty()) {
        for(int k=0; k<dead[i][j].size(); k++) {
          land[i][j] += dead[i][j][k] / 2;
        }
        dead[i][j].clear();
      }
    }
  }
}

void autumn() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(!tree[i][j].empty()) {
        for(int l=0; l<tree[i][j].size(); l++) {
          if(!(tree[i][j][l] % 5)) {
            for(int k=0; k<8; k++) {
              int nx = i + dir[k][0], ny = j + dir[k][1];
              if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
              tree[nx][ny].push_back(1);
            }
          }
        }
      }
    }
  }
}

void winter() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      land[i][j] += a[i][j];
    }
  }
}

int main() {
  cin>>N>>M>>K;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>a[i][j];
      land[i][j] = 5;
    }
  }
  for(int i=0; i<M; i++) {
    cin>>x>>y>>z;
    tree[x][y].push_back(z);
  }
  while(K--) {
    spring();
    summer();
    autumn();
    winter();
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      ans += tree[i][j].size();
    }
  }
  cout<<ans<<"\n";
  return 0;
}
