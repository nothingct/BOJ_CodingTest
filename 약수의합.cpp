#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX=1000000;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // f[i] : i의 모든 약수의 합이 들어감 = f(i)
  vector<long long> f(MAX+1,1);

  for(int i=2; i<=MAX; i++){
    for (int j=1; j*i<=MAX; j++){
      f[i*j] += i;
    }
  }
//  g[i] : f(1)~f(i) 까지의 합이 들어감 =g(i)
  vector<long long> g(MAX+1);
  for(int i=1; i<=MAX; i++){
    g[i] = g[i-1]+f[i];
  }

  int t;
  cin>>t;
  while(t--){
    int n ; 
    cin>>n;
    cout<<g[n]<<'\n';
  }
  return 0;
}