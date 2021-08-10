#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool go(vector<int>& a, int l){
  //한 줄 을 검사해서 지나갈 수 있는 지 여부를 반환
  //경사로 설치 여부 
  int n = a.size();
  vector<bool> c(n,false);
  for(int i=1; i<n; i++){//0은 맨 처음, 무조건 지날수 O
    if(a[i-1]!=a[i]){
      //높이가 다르다면, 경사로 놓을 수 있는지 확인.
      int diff = abs(a[i]-a[i-1]);
      //높이가 2이상 차이나면 경사로 못놓고 따라서 지나갈 수 X
      if( diff != 1) return false;
      //높이가 1차이나면 경사로를 놓을 수 있는데, 
      //경사로를 놓는 방법은 크게 낮->높 OR 높->낮 두 가지 경우임 
      //1.낮-> 높 의 경우
      if(a[i-1] < a[i]){
        //왼쪽에서부터 l개 연속이 가능한지를 판단. 
        for(int j=1; j<=l; j++){
          //배열범위 벗어나는 경우 
          if(i-j<0) return false;
          //왼쪽 에서부터 l개가 높이가 같은지
          if(a[i-1]!=a[i-j]) return false;
          //이미 경사로를 놓았는지 
          if(c[i-j]) return false;
          //아니라면 경사로를 설치한다. 
          c[i-j]=true;
        }
      }else{      //2.높->낮의 경우 a[i-1]>a[i] 
        //오른쪽에서부터 l개 연속이 가능한지 판단.
        for(int j=0; j<l; j++){
          //배열범위 벗어나는 경우 
          if(i+j >= n) return false;
          //오른쪽에서부터 l개가 높이가 같은지 
          if(a[i]!= a[i+j])return false;
          //이미 경사로를 놓았는지 
          if(c[i+j]) return false;
          //아니라면 경사로를 설치한다. 
          c[i+j]=true;
        }
      }
    }
  }
  return true;
}
int main(){
  int n ,l ;
  cin>>n>>l;

  vector<vector<int>> a(n,vector<int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for(int i=0; i<n; i++){
    //행검사 
    vector<int> d; 
    for(int j=0; j<n; j++){
       d.push_back(a[i][j]);
    }
    if(go(d,l)) ans+=1;
  }
  for(int j=0; j<n; j++){
    //열검사 
    vector<int> d; 
    for(int i=0; i<n; i++){
       d.push_back(a[i][j]);
    }
    if(go(d,l)) ans+=1;
  }
  cout<<ans<<'\n';
  return 0; 
}