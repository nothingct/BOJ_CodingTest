#include <iostream>
#include <string>

using namespace std;

int c[10][7]={
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

int main(){
  int s;
  string n;
  cin>>s>>n;
  int m=n.length();
  for(int i=0; i<5; i++){
    //가로에 대해서
    if(i==0||i==2||i==4){
      //각 숫자에 대하여
      for(int j=0; j<m; j++){
        int now = n[j]-'0';
        //각 숫자 사이는 공백, 첫 숫자 제외
        if(j!=0) cout<<' ';
        //가로의 맨 첫 칸은 공백 
        cout<<' ';
        //각 숫자가 디스플레이의 0,3,6 의 위치에 채워져야되는지 여부 판단.
        if((i==0&&c[now][0]) || (i==2&&c[now][3]) || (i==4&&c[now][6])){
          for(int k=0; k<s; k++) cout<<'-';
        }else{
          for(int k=0; k<s; k++) cout<<' ';
        }
        //가로의 맨 끝 칸은 공백
        cout<<' ';
      }
      //각 가로가 끝날 때마다 개행 
      cout<<'\n';
    }else{//세로에 대하여
      for(int l=0; l<s; l++){ // '|' 또는 ' ' 를 세로로 s번 채우는 로직 반복
        //각 숫자에 대하여
        for(int j=0; j<m; j++){
          int now = n[j] -'0';
          if(j!=0) cout<<' '; //첫 수가 아니라면 일단 공백
          //각 숫자가 디스플레이의 1,4 번째를 채워야하는지 판단(왼쪽 세로부분)
          if((i==1&&c[now][1])|| (i==3&&c[now][4])) cout<<'|';
          else cout<<' ';
          //세로의 가운데 는 공백 
          for(int k=0; k<s; k++) cout<<' ';
          //각 숫자가 디스플레이의 2,5번째를 채워야 하는지 판단( 오른쪽 세로부분)
          if((i==1&&c[now][2]) || (i==3&&c[now][5])) cout<<'|';
          else cout<<' ';
        }
        cout<<'\n';//개행 후 위 로직을 s번 반복
      }
    }
  }
  return 0;
}