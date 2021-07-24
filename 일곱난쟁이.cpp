#include <iostream>
#include <algorithm>

using namespace std;
const int CNT=9;
int arr[CNT];
int sum;
int main(){
  //CNT명의 전체 합 이 들어가있다.
  for(int i=0; i<CNT; i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  sort(arr, arr+CNT);

  //Brute Force : 1.제외될 두 명을 고른다 :first->second
  //              2.제외된 두명을 제외한 7명의 합을 구한다.
  //                3.합이 100일 경우 순서대로 출력하고 프로그램 종료
  //                4 합이 100이 아닐경우 1번으로 돌아간다.

  for (int i=0; i<CNT; i++){
    int first = i;
    for(int j=i+1; j<CNT; j++){
      int second = j;
      if(sum-(arr[first]+arr[second]) == 100){
        for(int k=0; k<CNT; k++){
          if(k==first || k==second ) continue;
          cout<<arr[k]<<'\n';
        }
        return 0;
      }
    }
  }
  return 0; 
}