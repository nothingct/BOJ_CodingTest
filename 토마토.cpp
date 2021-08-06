#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX = 100; 

int n,m,h;
int g[MAX+1][MAX+1][MAX+1];
int days[MAX+1][MAX+1][MAX+1];
int dx[]={-1,1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,1,-1};
int leftTomato;

int main(){
  cin>>m>>n>>h;
  queue<tuple<int,int,int>> q;
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >>g[i][j][k];
        if(g[i][j][k]==0) leftTomato++;
        if(g[i][j][k]==1) q.push({i,j,k});
      }
    }
  }
  if(leftTomato==0){
    cout<<0<<'\n';
    return 0;
  }
  int ans=0; 
  while(!q.empty()){
    int x= get<0>(q.front()); 
    int y = get<1>(q.front());
    int z = get<2>(q.front());
    ans = days[x][y][z];
    q.pop();
    for(int i=0; i<6; i++){
      int nx = x+dx[i];
      int ny = y + dy[i];
      int nz = z+ dz[i];
      if(nx>=0 && nx<n&& ny>=0&& ny<m && nz>=0 && nz <h && g[nx][ny][nz]==0 && days[nx][ny][nz]==0){
        days[nx][ny][nz]=days[x][y][z]+1;
        leftTomato--;
        q.push({nx,ny,nz});
      }
    }
  }
  if(leftTomato) cout<<-1<<'\n';
  else cout << ans<<'\n';
  return 0;
}