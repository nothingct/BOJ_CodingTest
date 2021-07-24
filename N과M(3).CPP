#include <iostream>
using namespace std;

const int MAX = 8;
int perm[MAX];
int n, m;
void makePermutations(int len)
{
  if (len == m)
  {
    for (int i = 1; i < m; i++)
    {
      cout << perm[i] << ' ';
    }
    cout << perm[m] << '\n';
    return;
  }
  for (int num = 1; num <= n; num++)
  {
    perm[len + 1] = num;
    makePermutations(len + 1);
  }
}

int main()
{
  cin >> n >> m;
  makePermutations(0);
  return 0;
}