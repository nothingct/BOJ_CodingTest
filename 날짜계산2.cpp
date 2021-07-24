#include <iostream>

using namespace std;
const int MOD_E = 15;
const int MOD_S = 28;
const int MOD_M = 19;
const int LAST_YEAR = MOD_E*MOD_S* MOD_M;
int main(){
  int e,s,m;
  cin>>e>>s>>m;
  e-=1; s-=1; m-=1;
  for(int year =0; year <LAST_YEAR; year++){
    if(year % MOD_E == e && year % MOD_S==s && year%MOD_M==m){
      cout<<year+1<<'\n';
      break;
    }
  }
  return 0;
}