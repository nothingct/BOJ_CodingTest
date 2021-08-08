#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[4][8];


int main(){
  for(int i=0; i<4; i++){
    string s;
    cin>>s;
    for(int j=0; j<8; j++){
      a[i][j]= s[j]-'0';
    }
  }
  int k; 
  cin>>k;
  while(k--){
    int n,dir;
    cin>>n>>dir;
    n-=1;
    vector<int> d(4);
    d[n]=dir; 
    // 톱니바퀴의 왼쪽부터 극이 서로 다른지 확인 
    for(int i=n-1; i>=0; i--){
      if(a[i][2]!=a[i+1][6]) d[i]=-d[i+1];
      else break;
    }
    // 톱니바퀴의 오른쪽부터 극이 서로 다른지 확인. 
    for(int i=n+1; i<4; i++){
      if(a[i-1][2]!=a[i][6]) d[i]=-d[i-1];
      else break;
    }
    //회전해야 하는 방향을 보고 회전해야 할 바퀴를 모두 회전한다. 
    for(int i=0; i<4; i++){
      if(d[i]==0) continue;
      if(d[i]==1){
        //시계 방향 
        int temp = a[i][7];
        for(int j=7; j>=1; j--){
          a[i][j]=a[i][j-1];
        }
        a[i][0]=temp;
      }else if(d[i]==-1){
        int temp = a[i][0];
        for(int j=0; j<7; j++){
          a[i][j]=a[i][j+1];
        }
        a[i][7]=temp;
      }
    }
  }
  int ans =0;
  for(int i=0; i<4; i++){
    if(a[i][0]==1){
      ans |= (1<<i);
    }
  }
  cout<<ans<<'\n';
}
