#include <iostream>
#include <vector>

using namespace std;

//a배열을 상하반전
vector<vector<int>> op1(vector<vector<int>> &a){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ret[i][j]=a[n-i-1][j];
    }
  }
  return ret;
}

//a배열을, 길이 l 짜리 부분배열을 한 칸으로 인식하여 상하반전.
vector<vector<int>> op5(vector<vector<int>> & a,int l){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  int sub_size= (1<<l);
  int sub_count = n/ sub_size;
  for(int i=0; i<sub_count; i++){
    for(int j=0; j<sub_count; j++){
      int x1=i*sub_size;
      int y1=j*sub_size;

      int x2=(sub_count-i-1)*sub_size;
      int y2=j*sub_size;

      for(int x=0; x<sub_size; x++){
        for(int y=0; y<sub_size; y++){
          ret[x1+x][y1+y]=a[x2+x][y2+y];
        }
      }
    }
  }
  return ret;
}

//a 배열을 좌우 반전 
vector<vector<int>> op2(vector<vector<int>> &a){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ret[i][j]=a[i][n-j-1];
    }
  }
  return ret;
}

//a배열을, 길이 l 짜리 부분배열을 한 칸으로 인식하여 좌우반전.
vector<vector<int>> op6(vector<vector<int>> & a,int l){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  int sub_size= (1<<l);
  int sub_count = n/ sub_size;
  for(int i=0; i<sub_count; i++){
    for(int j=0; j<sub_count; j++){
      int x1=i*sub_size;
      int y1=j*sub_size;

      int x2=i*sub_size;
      int y2=(sub_count-j-1)*sub_size;

      for(int x=0; x<sub_size; x++){
        for(int y=0; y<sub_size; y++){
          ret[x1+x][y1+y]=a[x2+x][y2+y];
        }
      }
    }
  }
  return ret;
}

//a배열을 시계방향으로 90도 회전 
vector<vector<int>> op3(vector<vector<int>> &a){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ret[i][j]=a[n-j-1][i];
    }
  }
  return ret;
}

//a배열을, 길이 l 짜리 부분배열을 한 칸으로 인식하여 시계방향으로 90도 회전 .
vector<vector<int>> op7(vector<vector<int>> & a,int l){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  int sub_size= (1<<l);
  int sub_count = n/ sub_size;
  for(int i=0; i<sub_count; i++){
    for(int j=0; j<sub_count; j++){
      int x1=i*sub_size;
      int y1=j*sub_size;

      int x2=(sub_count-j-1)*sub_size;
      int y2=i*sub_size;

      for(int x=0; x<sub_size; x++){
        for(int y=0; y<sub_size; y++){
          ret[x1+x][y1+y]=a[x2+x][y2+y];
        }
      }
    }
  }
  return ret;
}


//a배열을 반시계방향으로 90도 회전 
vector<vector<int>> op4(vector<vector<int>> &a){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ret[i][j]=a[j][n-i-1];
    }
  }
  return ret;
}

//a배열을, 길이 l 짜리 부분배열을 한 칸으로 인식하여 반시계방향으로 90도 회전 .
vector<vector<int>> op8(vector<vector<int>> & a,int l){
  int n = a.size();
  vector<vector<int>> ret(n,vector<int>(n));
  int sub_size= (1<<l);
  int sub_count = n/ sub_size;
  for(int i=0; i<sub_count; i++){
    for(int j=0; j<sub_count; j++){
      int x1=i*sub_size;
      int y1=j*sub_size;

      int x2=j*sub_size;
      int y2=(sub_count-i-1)*sub_size;

      for(int x=0; x<sub_size; x++){
        for(int y=0; y<sub_size; y++){
          ret[x1+x][y1+y]=a[x2+x][y2+y];
        }
      }
    }
  }
  return ret;
}

//a에 대하여 k번 op를 길이가 len인 (sx,sy) 를 좌상단으로 갖는 부분배열에 대하여 적용한다.
//op1~op4 는 각 부분배열에 대하여 op1~op4를 실시
void opFrom1to4(vector<vector<int>> &a,int k, int sx, int sy,int len){
  vector<vector<int>> b(len,vector<int>(len));
  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      b[i][j] = a[sx+i][sy+j];
    }
  }
  if(k==1) b= op1(b);
  else if(k==2) b= op2(b);
  else if(k==3) b= op3(b);
  else if(k==4) b= op4(b);
  //길이 len인 (sx,sy)를 좌상단으로 갖는 부분배열의 op결과를 반영한다. 
  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      a[sx+i][sy+j]=b[i][j];
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, r; 
  cin>>n >> r ;
  int size = (1<<n);
  vector<vector<int>> a(size,vector<int>(size));
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      cin>>a[i][j];
    }
  }
  while(r--){
    //op: k , level : l
    int k,l;
    cin>>k>>l;
    int sub_size= (1<<l);
    if(1<=k && k<=4){
      for(int i=0; i<size; i+=sub_size){
        for(int j=0; j<size; j+=sub_size){
          opFrom1to4(a,k,i,j,sub_size);
        }
      }
    }else if(5<=k&& k<=8){
      if(k==5) a= op5(a,l);
      else if(k==6) a=op6(a,l);
      else if(k==7) a=op7(a,l);
      else if(k==8) a=op8(a,l);
    }
  }
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      cout<<a[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}