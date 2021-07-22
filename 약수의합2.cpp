// g(n) = g(n-1) + f(n) ,g(1) = f(1) = 1
// f(n)= n의 모든 약수의 합. 
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  
  int n ; 
  cin>>n;

  long long gn= 0 ; 
  for(int i=1; i<=n; i++){
    gn+=(n/i)*i;
  }
  cout<<gn<<'\n';
  return 0;
}
