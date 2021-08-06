#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 2000;
//g[화면개수][클립보드개수]
int dist[MAX+1][MAX+1];

int main(){
  int s;
  cin>>s;

  for(int i=0; i<=MAX; i++){
    for(int j=0; j<=MAX; j++){
      dist[i][j]=-1;
    }
  }
  queue<pair<int,int>> q; 
  q.push({1,0});
  dist[1][0] = 0;
  int ans = 0;
  while(!q.empty()){
    int screen = q.front().first;
    int clip = q.front().second;
    q.pop();
    if (screen==s) {
      ans=dist[screen][clip];
      break;
    }
    //1. s,c-> s,s 
    if(dist[screen][screen]==-1){
      dist[screen][screen]=dist[screen][clip]+1;
      q.push({screen,screen});
    }
    //2  s,c-> s-1,c
    if(dist[screen-1][clip]==-1){
      if(screen-1>=0){
        dist[screen-1][clip]=dist[screen][clip]+1;
        q.push({screen-1,clip});
      }
    }
    //3 s,c -> s+c,c ( c!=0)
    if(dist[screen+clip][clip]==-1){
      if(screen+clip <=MAX){
        dist[screen+clip][clip]=dist[screen][clip]+1;
        q.push({screen+clip,clip});
      }
    }
  }
  cout<<ans<<'\n';
}