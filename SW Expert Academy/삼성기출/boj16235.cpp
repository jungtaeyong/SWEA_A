#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K, a[11][11], feed[11][11];
vector<int> info[11][11], dead[11][11];
const int dist[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void spring() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(!info[i][j].empty()) {
        sort(info[i][j].begin(), info[i][j].end());
        for(vector<int>::iterator it=info[i][j].begin(); it!=info[i][j].end(); it++) {
          if(feed[i][j] >= *it) {
            feed[i][j] -= *it;
            (*it)++;
          } else {
            dead[i][j].insert(dead[i][j].end(), it, info[i][j].end());
            info[i][j].erase(it, info[i][j].end());
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
          feed[i][j] += dead[i][j][k] / 2;
        }
        dead[i][j].clear();
      }
    }
  }
}

void autumn() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(!info[i][j].empty()) {
        for(int k=0; k<info[i][j].size(); k++) {
          if(info[i][j][k] % 5 == 0) {
            for(int l=0; l<8; l++) {
              int nx = i + dist[l][0], ny = j + dist[l][1];
              if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
              else info[nx][ny].push_back(1);
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
      feed[i][j] += a[i][j];
    }
  }
}

int main(){
  int alive = 0;
  cin>>N>>M>>K;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>a[i][j];
      feed[i][j] = 5;
    }
  }
  for(int i=0; i<M; i++) {
    int x, y, age;
    cin>>x>>y>>age;
    info[x][y].push_back(age);
  }
  
  for(int i=0; i<K; i++) {
    spring();
    summer();
    autumn();
    winter();
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      alive += info[i][j].size();
    }
  }
  cout<<alive<<"\n";
  return 0;
}
