#include <iostream>
using namespace std;

const int MAX = 8;
int perm[MAX + 1];
int n, m;
void makePermutations(int len,int start)
{
  if( len == m ) {
    for(int i=0; i<m-1; i++){
      cout<<perm[i]<<' ';
    }
    cout<<perm[m-1]<<'\n';
    return;
  }
  for(int i=start; i<=n; i++){
    perm[len] = i;
    makePermutations(len+1,i+1);
  }
}

int main()
{
  cin >> n >> m;
  makePermutations(0,1);
  return 0;
}