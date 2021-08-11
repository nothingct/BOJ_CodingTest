#include <iostream>
#include <algorithm>
using namespace std; 

const int MAX =300; 
int b[MAX*2+1][MAX*2+1];

int main(){
  int h,w,x,y;
  cin>>h>>w>>x>>y;

  for(int i=0; i<h+x; i++){
    for(int j=0; j<w+y; j++){
      cin>>b[i][j];
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      b[i+x][j+y] -=b[i][j];
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j <w; j++){
      cout<<b[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}