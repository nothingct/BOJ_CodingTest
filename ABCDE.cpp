#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//인접행렬, 인접리스트, 간선리스트를 모두 사용하여 문제를 풀어보기 ( 학습 차원 ) 
const int MAX= 2000;
bool a[MAX][MAX]; // 인접 행렬 
vector<int> g[MAX]; //인접 리스트 
vector<pair<int,int>> edges; //간선 리스트


int main(){
  int n,m; // n : 정점(사람의 수 ), m: 간선( 친구 관계의 수 => 양방향그래프 암시)
  cin >> n>>m;
  for (int i=0; i<m; i++){
    int from, to ; 
    cin >> from >> to ; //from=>to , to=>from 모두 저장해줘야함(양방향그래프)
    //간선리스트 저장 
    edges.push_back({from,to});
    edges.push_back({to,from});
    //인접행렬 저장 
    a[from][to]=a[to][from]= true;
    //인접리스트 저장 
    g[from].push_back(to);
    g[to].push_back(from); 
  } 
  m*=2; //실제 간선의 개수 는 양방향이므로 2배 
  //모든 간선을 조사
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      //간선리스트 => A->B  와 C->D 간선 찾기 
      //A->B
      int A = edges[i].first;
      int B = edges[i].second;
      //C->D
      int C = edges[j].first;
      int D = edges[j].second;
      //A,B,C,D 가 겹치지 않는지 확인 
      if(A==B || A==C||A==D||B==C||B==D||C==D) continue;
      //인접행렬=> B->C 간선 찾기 
      if(!a[B][C]) continue;
      //인접 리스트 => D-> E 간선 찾기 
      for(int E: g[D]){
        if(A==E||B==E||C==E||D==E) continue;
        cout << 1<<'\n';
        return 0;
      }
    }
  }
  cout<<0<<'\n';
  return 0;
}