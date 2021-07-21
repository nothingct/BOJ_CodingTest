#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int cnt;
  cin>>cnt;
  int a[505];
  for(int i=0; i<cnt; i++){
      cin>>a[i];
  }
  sort(a,a+cnt);
  cout<<a[0]*a[cnt-1]<<'\n';
}