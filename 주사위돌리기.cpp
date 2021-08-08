#include <iostream>
using namespace std;

int a[20][20];
int dice[7];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main(){
  int n,m,x,y,k;
  cin>>n>>m>>x>>y>>k;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>a[i][j];
    }
  }
  while(k--){
    int d;
    cin>>d;
    d-=1;
    int nx=x+dx[d];
    int ny=y+dy[d];
    //바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시 AND 출력도 하면 안됨.
    if(nx<0||nx>=n||ny<0||ny>=m) continue;
    //주사위 이동에 따른 면의 상태 변경
    //오른쪽
    if(d==0){
      int temp = dice[1];
      dice[1]=dice[4];
      dice[4]=dice[6];
      dice[6]=dice[3];
      dice[3]=temp;
    }else if(d==1){
    //왼쪽
      int temp = dice[1];
      dice[1]=dice[3];  
      dice[3]=dice[6];
      dice[6]=dice[4];
      dice[4]=temp;
    }else if(d==2){
    //위쪽
      int temp = dice[1];
      dice[1]=dice[5];
      dice[5]=dice[6];
      dice[6]=dice[2];
      dice[2]=temp;
    }else if(d==3){
    //아래쪽
      int temp = dice[1];
      dice[1]=dice[2];
      dice[2]=dice[6];
      dice[6]=dice[5];
      dice[5]=temp;
    }
    //주사위 이동 
    x=nx;
    y=ny;
    //이동 한 칸의 수 가 0 이면 
    if(a[x][y]==0){
      //주사위 밑면의 수가 해당 칸에 복사됨.
      a[x][y]=dice[6];
    } else{
      //이동한 칸의 수가 0이 아니라면 
      //해당 칸의 수가 주사위 의 바닥면에 복사됨
      dice[6]=a[x][y];
      //해당 칸은 0이 된다. 
      a[x][y]=0;
    }
    //각 이동에 따른 윗 면의 수를 출력한다. 
    cout<<dice[1]<<'\n';
  }
  return 0; 
}