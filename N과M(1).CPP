#include <iostream>
using namespace std;

const int MAX=8;
bool visited[MAX+1];
int perm[MAX+1];
int n,m;
void makePermutations(int len){
  if(len == m){
    for(int i=1; i<m; i++){
      cout<<perm[i]<<' ';
    }
    cout<<perm[m]<<'\n';
    return;
  }
  for(int num =1; num<=n; num++){
    if(!visited[num]){
      visited[num]= true;
      perm[len+1]=num;
      makePermutations(len+1);
      visited[num] = false;
    }
  }
}

int main(){
  cin>>n>>m;
  makePermutations(0);
  return 0;
}