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

void go ( int sum , int cnt ,int startX,int startY) {
  if (cnt== k ) {
    ans = max(ans,sum);
    return ; 
  }
  for(int i=startX; i<n; i++){
    for(int j=(i==startX?startY:0); j<m; j++){
      if(c[i][j]) continue;
      bool isPossible= true;
      for(int d=0; d<2; d++){
        int x= i+dx[d];
        int y= j+dy[d];
        if(0>x || x>=n || 0>y || y>=m) continue;
        if(c[x][y]) isPossible = false;
      }
      if(isPossible){
        c[i][j] = true;
        go(sum+a[i][j],cnt+1,i,j);
        c[i][j] = false;
      }
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
  go(0,0,0,0);
  cout<<ans<<'\n';
}