// 문제
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 
//만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

// 출력
// 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

//순간이동 의 가중치. 비용이 0 이므로, 우선 시작점에서 순간이동이 가능한 부분들은 모두 큐에 넣는다 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

const int MAX= 100000*2;

int n,k;
bool checked[MAX+1];
int dist[MAX+1];
int bfs(int s, int e){
  deque<int> q;
  q.push_back(s);
  checked[s]=true;
  dist[s]=0;
  while(!q.empty()){
    int now = q.front();
    q.pop_front();
    if(now==e) break;
    if(now*2 <MAX){
      if(checked[now*2]==false){
        checked[now*2]=true;
        dist[now*2] = dist[now];
        q.push_front(now*2);
      }
    }
    if(now-1>=0){
      if(checked[now-1]==false){
        checked[now-1] = true;
        dist[now-1] = dist[now]+1;
        q.push_back(now-1);
      }
    }
    if(now+1 <MAX){
      if(checked[now+1] == false){
        checked[now+1]= true;
        dist[now+1] = dist[now]+1;
        q.push_back (now+1);
      }
    }
  }
  return dist[e];
}

int main(){
  cin>>n>>k;
  cout<<bfs(n,k)<<'\n';
}