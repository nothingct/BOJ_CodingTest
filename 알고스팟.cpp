#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;
const int MAX = 100;
int g[MAX+1][MAX+1];
int dist[MAX+1][MAX+1];
bool check[MAX+1][MAX+1];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
int main(){
  cin>>m>>n;
  deque<pair<int,int>> dq;
  for(int i=0; i<n; i++){
    string s;
    cin>>s;
    for(int j=0; j<s.length(); j++){
      g[i][j] = s[j]-'0';
    }
  }
  //시작점 
  check[0][0]= true;
  dist[0][0] =0; 
  dq.push_back({0,0});
  while(!dq.empty()){
    int x = dq.front().first;
    int y = dq.front().second; 
    dq.pop_front();
    if(x==n-1 && y== m-1 ) break;
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i]; 
      if(nx<0||nx>=n||ny<0||ny>=m) continue;
      if(check[nx][ny]) continue;
      check[nx][ny] = true;
      if(g[nx][ny] == 0 ){
        dist[nx][ny] = dist[x][y] ; 
        dq.push_front({nx,ny});
      }else{
        dist[nx][ny]= dist[x][y]+1;
        // g[nx][ny]=0; // 굳이 0으로 안 바꾸어도 됨 
        /* 모든 움직임의 경우의 수 
        빈 방-> 빈 방 : 0 
        빈 방-> 벽 : 1 
        벽 -> 빈 방 : 0 (벽에서 이동했다는 것은 , 해당 벽은 이미 부수어졌음을 의미 ) 
        벽 -> 벽 : 1
        결론 => 다음 방문이 빈 방이면 0, 벽이면 1로 동일. 
        */
        dq.push_back({nx,ny});
      }
    }
  }
  cout<<dist[n-1][m-1]<<'\n';
}