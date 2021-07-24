#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    x -= 1;
    y -= 1;
    bool isPossible = false;
    for (int year = x; year < n * m; year += m)
    {
      int cur_y = year % n;
      if (cur_y == y)
      {
        isPossible = true;
        cout << year + 1 << '\n';
        break;
      }
    }
    if (!isPossible)
      cout << -1 << '\n';
  }
}