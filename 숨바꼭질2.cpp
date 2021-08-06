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
  int minTime =-1;
  int ansTime=0;
  
  queue<pair<int,int>> q; 
  q.push({n,0});
  checked[n] = true;
  while(!q.empty()){
    int cur =q.front().first;
    int curTime = q.front().second;
    checked[cur]=true;
    q.pop();
    if(cur==k) {
      if(minTime==-1){
        minTime=curTime;
        ansTime ++;
      }
      else if( minTime==curTime){
        ansTime++;
      }
    }
    if(cur-1>=0) {
      if(checked[cur-1]==false){
        q.push({cur-1,curTime+1});
      }
    }
    if(cur+1 <MAX){
      if(checked[cur+1] == false){
        q.push({cur+1,curTime+1});
      }
    }
    if(cur*2 <MAX){
      if(checked[cur*2]==false){
        q.push({cur*2,curTime+1});
      }
    }
  }
  cout<<minTime<<'\n';
  cout<<ansTime<<'\n';
}