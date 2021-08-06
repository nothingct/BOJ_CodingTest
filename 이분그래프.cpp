#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std ;
const int MAX = 20000;
vector<int> g[MAX+1];
int color[MAX+1];

bool dfs(int node, int c){
  color[node]= c;
  for(int i=0; i < g[node].size(); i++){
    int next= g[node][i];
    if(color[next]== 0 ){
      if(dfs(next,3-c)==false) return false;
    }else if(color[next] == color[node] ) return false;
  }
  return true;
}

int main(){
  int t; 
  cin >>t ; 
  while(t--){
    int n , m ;
    cin>>n>>m;
    //초기화 : color 배열 , graph
    for(int i=1; i<=n; i++){
      g[i].clear();
      color[i] = 0;
    }
    for(int i=0; i<m; i++){
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bool ok = true;
    for (int i=1; i<=n; i++){
      if(color[i]==0){
        if(dfs(i,1)== false) ok = false;
      }
    }
    printf("%s\n",ok?"YES":"NO");
  }
  return 0;
}