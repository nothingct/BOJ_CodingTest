#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAX=25;
int g[MAX+1][MAX+1];
bool c[MAX+1][MAX+1];
vector<int> numOfHouse;
int n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x,int y){
  c[x][y]=true;
  int cnt =1;
  for(int i=0; i<4; i++){
    int nx = x+ dx[i];
    int ny = y +dy[i];
    if(nx<0||nx>=n||ny<0||ny>=n) continue;
    if(g[nx][ny] == 0 ) continue;
    if(c[nx][ny]) continue;
    cnt+=dfs(nx,ny);
  }
  return cnt;
}

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    string temp;
    cin>>temp;
    for(int j=0; j<n; j++){
      g[i][j] = temp[j]-'0';
    }
  }

  int num =0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(g[i][j] && !c[i][j]){
        int num = dfs(i,j);
        numOfHouse.push_back(num);
      }
    }
  }

  sort(numOfHouse.begin(),numOfHouse.end());
  cout<<numOfHouse.size()<<'\n';
  for(int i=0; i<numOfHouse.size(); i++){
    cout<<numOfHouse[i]<<'\n';
  }
}