#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 300;
int a[MAX][MAX];

int main(){
  int n,m,r; 
  cin>>n>>m>>r;
  for(int i=0; i<n; i++){
    for(int j=0; j <m; j++){
      cin >>a[i][j];
    }
  }
  vector<vector<int>> groups ; 
  int groupN = min(n,m)/2;
  //grouping: group K -바깥으로부터 K칸 떨어진 그룹
  //좌상단-> 우상단, 우상단->우하단, 우하단->좌하단, 좌하단-> 좌상단 순서로 (모서리칸은 제외)
  //k번쨰 그룹의 모든 원소를 1차원 배열인 group에 집어놓는다. 
  //groups 에 k번쨰 그룹이 담긴 1차원 배열 group을 순서대로 넣는다.
  for(int k=0; k<groupN; k++){
    vector<int> group;
    //좌상단->우상단
    for(int j=k; j<m-k; j++){
      group.push_back(a[k][j]);
    }
    //우상단->우하단
    for(int i=k+1; i<n-k-1; i++){
      group.push_back(a[i][m-k-1]);
    }
    //우하단->좌하단 
    for(int j=m-k-1; j>k; j--){
      group.push_back(a[n-k-1][j]);
    }
    //좌하단->좌상단 
    for(int i=n-k-1; i>k; i--){
      group.push_back(a[i][k]);
    }
    groups.push_back(group);
  }
  //그루핑과 각 그룹의 모든 원소를 1차원 배열 그룹에 모두 저장한 후, 
  //r칸 반시계 방향 으로 돌린다는 것은 인덱스 i 의 입장에선
  // (i+r)%그룹의길이 인덱스 번째 원소의 값을 갖게 됨을 의미한다.
  //해당 값을 실제 2차원 배열에 , 그루핑을 할 때 지정한 순서와 동일하게 반영한다. 
  for(int k=0; k<groupN; k++){
    vector<int> &group= groups[k];
    int len = group.size();
    int index = r % len;
    //좌상단->우상단
    for(int j=k; j<m-k; j++,index=(index+1)%len){
      a[k][j] = group[index];
    }
    //우상단->우하단
    for(int i=k+1; i<n-k-1; i++,index=(index+1)%len){
      a[i][m-k-1] =group[index];
    }
    //우하단->좌하단 
    for(int j=m-k-1; j>k; j--,index=(index+1)%len){
      a[n-k-1][j] = group[index];
    }
    //좌하단->좌상단 
    for(int i=n-k-1; i>k; i--,index=(index+1)%len){
      a[i][k]=group[index];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j <m; j++){
      cout <<a[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}