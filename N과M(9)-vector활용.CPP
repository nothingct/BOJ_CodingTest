#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int perm[9];
bool visited[9];
int arr[9];
int n,m;
// 1. vector->모든 순열 저장 후 중복을 erase(unique()) 로 제거 
vector<vector<int>> perms;

void makePermutations(int len){
  if(len == m ){
    vector<int> res;
    for(int i=0; i<m; i++){
      res.push_back(perm[i]);
    }
    perms.push_back(res);
    return;
  }
  for(int i=0; i<n; i++){
    if(visited[i]) continue;
    visited[i] = true;
    perm[len]=arr[i];
    makePermutations(len+1);
    visited[i] = false;
  }
}

int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  makePermutations(0);
  sort(perms.begin(),perms.end());
  perms.erase(unique(perms.begin(),perms.end()),perms.end());
  for ( auto &p : perms){
    for(int i=0; i<m; i++){
      cout<<p[i];
      if(i != m -1){
        cout<<' ';
      }
    }
    cout<<'\n';
  }
  return 0;
}