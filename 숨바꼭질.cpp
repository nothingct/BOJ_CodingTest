#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100000*2;
bool checked[MAX+1];

int main(){
  int n,k;
  cin>>n>>k;

  queue<pair<int,int>> q; 
  q.push({n,0});
  checked[n] = true;
  while(!q.empty()){
    int cur =q.front().first;
    int curTime = q.front().second;
    q.pop();
    if(cur==k) {
      cout<<curTime<<'\n';
      break;
    }
    if(cur-1>=0) {
      if(checked[cur-1]==false){
        q.push({cur-1,curTime+1});
        checked[cur-1]=true;
      }
    }
    if(cur+1 <MAX){
      if(checked[cur+1] == false){
        q.push({cur+1,curTime+1});
        checked[cur+1] = true;
      }
    }
    if(cur*2 <MAX){
      if(checked[cur*2]==false){
        q.push({cur*2,curTime+1});
        checked[cur*2] = true;
      }
    }
  }
}