#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n,k;
  cin>>n>>k;

  vector<int> a(2*n);
  for(int i=0; i<2*n; i++){
    cin>>a[i];
  }
  vector<bool> box(2*n,false);
  int zeroCnt=0;
  int timePassed =1;
  while(true){
    rotate(a.rbegin(),a.rbegin()+1,a.rend());
    rotate(box.rbegin(),box.rbegin()+1,box.rend());
    if(box[n-1]) box[n-1]=false;
    for(int i=n-2; i>=0; i--){
      if(box[i]){
        if(!box[i+1]&& a[i+1]>0){
          box[i+1]=true;
          box[i]=false;
          a[i+1]-=1;
          if(a[i+1]==0) zeroCnt+=1;
        }
      }
    }
    if(box[n-1]) box[n-1]=false;
    if(a[0]>0){
      box[0]=true;
      a[0]-=1;
      if(a[0]==0) zeroCnt+=1;
    }
    if(zeroCnt>=k){
      cout<<timePassed<<'\n';
      break;
    }
    timePassed+=1;
  }
  return 0;
}