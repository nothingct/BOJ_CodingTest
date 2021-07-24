#include <iostream>
using namespace std;

const int LAST_YEAR = 15*28*19;

int main(){
  int e,s,m;
  cin>>e>>s>>m;
  // 1~LASY_YEAR 까지 전부 돌면서 각각을 15,28,19 로 잘 나눈 나머지가 e,s,m이면 해당 year를 출력하고 종료
  int cur_e=1,cur_s=1,cur_m=1;
  for(int year =1; year<=LAST_YEAR; year++){
    if(e==cur_e&&s==cur_s&&m==cur_m){
      cout<<year<<'\n';
      break;
    }
    cur_e++; cur_s++; cur_m++;
    if(cur_e==16) cur_e=1;
    if(cur_s==29) cur_s=1;
    if(cur_m==20) cur_m=1;
  }
  return 0;
}