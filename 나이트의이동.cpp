#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX=300;
int n,ans;
int startX, startY,endX,endY;
int visited[MAX+1][MAX+1];
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};


void initMap(){
  for(int i=0; i<=MAX; i++){
    for(int j=0; j<=MAX; j++){
      visited[i][j]=-1;
    }
  }
}

int main(){
  int t; 
  cin>>t;
  while(t--){
    cin>>n;
    cin>>startX>>startY;
    cin>>endX>>endY;
    initMap();
    queue<pair<int,int>> q; 
    q.push({startX,startY});
    visited[startX][startY]=0;
    while(!q.empty()){
      int x =q.front().first;
      int y = q.front().second;
      q.pop();
      if(x==endX&& y== endY) {
        ans = visited[x][y];
        break;
      }
      for(int i=0; i <8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || nx >=n || ny<0|| ny>=n) continue;
        if(visited[nx][ny]!=-1) continue;
        visited[nx][ny] = visited[x][y]+1;
        q.push({nx,ny});
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}