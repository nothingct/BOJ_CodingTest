#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int MAX = 100; 
int n,m;
int g[MAX+1][MAX+1];
int c[MAX+1][MAX+1];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int sx,int sy){
  queue < pair<int, int>> q;
  q.push(make_pair(sx,sy));
  c[sx][sy]= 1;

  while(!q.empty()){
    int x= q.front().first;
    int y= q.front().second;
    q.pop();
    if(x==n-1 && y== m-1) break;
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 ||nx >= n|| ny<0 || ny>=m ) continue;
      if(g[nx][ny]==0) continue;
      if(c[nx][ny]!=0) continue;
      c[nx][ny]=c[x][y]+1;
      q.push(make_pair(nx,ny));
    }
  }
  return c[n-1][m-1];
}

int main(){
  cin>>n>>m;
  
  for(int i=0; i<n; i++){
    string temp;
    cin>>temp;
    for(int j=0; j<m; j++){
      g[i][j] =temp[j]-'0'; 
    }
  }

  cout<<bfs(0,0)<<'\n';
}