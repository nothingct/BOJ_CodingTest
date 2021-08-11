#include <iostream>
using namespace std;
const int MAX = 101;
int a[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
  int n ,m ; 
  cin>>n>>m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin>>a[i][j]; 
    }
  }
  int ans = 2*n*m;
  for(int x=1; x<=n; x++){
    for(int y=1; y<=m; y++){
      for(int d=0; d<4; d++){
        int nx = x+dx[d];
        int ny= y+dy[d];
        if(a[x][y] - a[nx][ny]>0){
          ans+= a[x][y]-a[nx][ny];
        }
      }
    }
  }
  cout<<ans<<'\n';
}