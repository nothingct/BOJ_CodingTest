#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std; 

const int MAX = 1001;
bool check[MAX];
vector<int> g[MAX];
void dfs(int x){
  check[x] =true;
  printf("%d ",x);
  for(int i=0; i<g[x].size(); i++){
    int y = g[x][i]; 
    if(!check[y]){
      dfs(y);
    }
  }
}

int main(){
  int n,m,start;
  cin>>n>>m>>start;
  for(int i=0; i<m; i++){
    int u,v; 
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i=1; i<=n; i++) sort(g[i].begin(),g[i].end());

  dfs(start);

  for(int i=1; i<=n; i++) check[i] = false;
  printf("\n");
  queue<int> q; 
  check[start]=true; q.push(start);
  while(!q.empty()){
    int x= q.front(); q.pop();
    printf("%d ",x);
    for(int i=0; i<g[x].size(); i++){
      int y = g[x][i];
      if(!check[y]){ check[y]=true; q.push(y); }
    }
  }
}