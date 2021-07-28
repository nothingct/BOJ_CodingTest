#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;
int a[MAX+1][MAX+1];
bool c[MAX+1][MAX+1];
int n,m,k;
int ans = -10000*4;
//사실 좌상단부터 검색하기에 이전의 인접 정보역시 좌,상단만 확인하면된다.
int dx[] = {-1,0};
int dy[] = {0,-1};

void go ( int sum , int cnt ,int prev) {
  if (cnt== k ) {
    ans = max(ans,sum);
    return ; 
  }
  for(int i=prev; i<n*m; i++){
      int x = i/m;
      int y = i%m;
      if(c[x][y]) continue;
      bool isPossible= true;
      for(int d=0; d<2; d++){
        int nx= x+dx[d];
        int ny= y+dy[d];
        if(0>nx || nx>=n || 0>ny || ny>=m) continue;
        if(c[nx][ny]) isPossible = false;
      }
      if(isPossible){
        c[x][y] = true;
        go(sum+a[x][y],cnt+1,x*m+y);
        c[x][y] = false;
      }
    }
  }


int main(){
  cin >>n>>m>>k;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>a[i][j];
    }
  }
  go(0,0,0);
  cout<<ans<<'\n';
}