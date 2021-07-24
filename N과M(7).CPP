#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int perm[9];
int arr[9];

void makePermutations(int len)
{
  if (len == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << perm[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++)
  {
    perm[len] = arr[i];
    makePermutations(len + 1);
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  makePermutations(0);
}