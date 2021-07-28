#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1001;
vector<int> g[MAX];
bool check[MAX];

void dfs(int x){
  check[x] = true;
  for(int i=0 ; i <g[x].size(); i++){
    int y = g[x][i];
    if(!check[y]) dfs(y);
  }
}

void bfs(int start){
  queue<int> q;
  check[start]=true; q.push(start);
  while(!q.empty()){
    int x = q.front(); q.pop();
    for(int i=0; i<g[x].size(); i++){
      int y = g[x][i];
      if(!check[y]){
        check[y]=true; q.push(y);
      }
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0; i<m; i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans =0;
  for(int i=1; i<=n; i++){
    if(!check[i]){
      ans++;
      // dfs(i);
      bfs(i);
    }
  }
  cout<<ans<<'\n';
}