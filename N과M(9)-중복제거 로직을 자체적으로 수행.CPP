#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[9];
bool ch[9];
int temp;
vector<int> v;
void go(int x, int cnt)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << v[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int temp = false;
  for (int i = 1; i <= n; i++)
  {
    if (ch[i] == false && temp != arr[i])
    {
      v.push_back(arr[i]);
      temp = arr[i]; //같은 depth안에 더이상 arr[i]와 같은 수가 나오지 않도록 설정
      ch[i] = true;
      go(i, cnt + 1);
      ch[i] = false;
      v.pop_back();
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  sort(arr, arr + n + 1);
  go(1, 0);
}