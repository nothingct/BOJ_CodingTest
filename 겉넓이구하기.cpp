#include <iostream>
using namespace std;

const int MAX = 101;
int a[MAX][MAX];

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>a[i][j];
    }
  }
  //윗면, 아랫면 의 겉넓이
  int ans = n*m*2;
  //앞면,뒷면
  for(int i=0; i<n; i++){
    int cnt=a[i][0];
    for(int j=1; j<m;j++){
      if(a[i][j]>a[i][j-1]) cnt+=(a[i][j]-a[i][j-1]);
    }
    ans+=cnt;
    cnt=a[i][m-1];
    for(int j=m-2; j>=0; j--){
      if(a[i][j]>a[i][j+1]) cnt+=(a[i][j]-a[i][j+1]);
    }
    ans+=cnt;
  }
  //왼쪽 면 오른쪽 면 
  for(int j=0; j<m; j++){
    int cnt =a[0][j];
    for(int i=1; i<n; i++){
      if(a[i][j] > a[i-1][j]) cnt+=(a[i][j]-a[i-1][j]);
    }
    ans+=cnt;
    cnt=a[n-1][j];
    for(int i=n-2; i>=0; i--){
      if(a[i][j] > a[i+1][j] ) cnt+=(a[i][j]-a[i+1][j]);
    }
    ans+=cnt;
  }
  cout<<ans<<'\n';
}