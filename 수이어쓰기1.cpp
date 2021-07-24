#include <iostream>
using namespace std;


int main(){
  long long ans=0;
  int n ; 
  cin >>n;
  for(int start =1, len=1; start<=n; start*=10, len++){
    int end = start*10 - 1;
    if(end > n ) end =n;
    ans += ( end - start + 1) * len;
  }
  cout<<ans<<'\n';
  return 0;
}