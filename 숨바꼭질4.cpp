  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <queue>

  using namespace std;

  const int MAX = 100000*2;
  bool check[MAX+1];
  int dist[MAX+1];
  int from[MAX+1];

  void printMove(int start, int end){
    if(start!=end){
      printMove(start,from[end]);
    }
    cout<<end<<' ';
  }

  int main(){
    int n,k;
    cin>>n>>k;
    queue<int> q;
    q.push(n);
    dist[n]=0;
    check[n]=true;
    while(!q.empty()){
      int now = q.front(); q.pop();
      if (now==k) break;
      if (now *2 <MAX && !check[now*2]){
        check[now*2] = true;
        dist[now*2] = dist[now]+1;
        q.push(now*2);
        from[now*2]=now;
      }
      if (now +1 <MAX && !check[now+1] ){
        check[now+1]=true;
        dist[now+1] = dist[now]+1;
        q.push(now+1);
        from[now+1]=now;
      }
      if ( now-1 >= 0 && !check[now-1] ){
        check[now-1]=true;
        dist[now-1]=dist[now]+1;
        q.push(now-1);
        from[now-1] = now;
      }
    }
    cout<<dist[k]<<'\n';
    printMove(n,k);
    cout<<'\n';

  }