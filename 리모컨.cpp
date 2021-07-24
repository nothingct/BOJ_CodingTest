#include <iostream>
#include <algorithm>

using namespace std;

const int CUR_POS=100;
const int MAX = 500000;
bool brokenNum[10];
//숫자 x를 버튼으로 누를 수 있는지 판단=>
// 누를수 없다면 0, 누를 수 있다면 X의 자릿수를 반환.
int isPossible(int x){
  //예외 처리 : x 가 0 
  if( x == 0 ){
    if(brokenNum[x]) return 0;
    else return 1;
  }
  // x가 1이상이라면
  int cnt=0;
  while( x != 0 ){
    int num = x%10;
    if(brokenNum[num]) return 0;
    else cnt+=1;
    x/=10;
  }
  return cnt;
}

int main(){
  int n,m; 
  cin>>n;
  cin>>m;
  while(m--){
    int btn;
    cin>>btn;
    brokenNum[btn]=true;
  }
  int ans = abs(CUR_POS-n);
  for(int x = 0; x<= MAX*2; x++){
    int cnt = isPossible(x);
    if(cnt == 0 ) continue;
    cnt += abs(x-n);
    ans= min(ans,cnt);
  }
  cout<<ans<<'\n';
  return 0;
}