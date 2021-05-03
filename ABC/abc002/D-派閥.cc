#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// 0100 1000 0011
// 1, 4, 10, 11
// (1, 4), (1, 10), (1, 11)
// (4, 10), (4, 11)
// (10, 11)

int main() {
  int n, m, i, j;
  int ret = 0;
  cin >> n >> m;
  vector<int> x(m), y(m);
  for (i = 0; i < m; i++)
    cin >> x.at(i) >> y.at(i);
  for (i = 0; i < (1<<n); i++) {
    bitset<12> b(i);
    int k = 0;
    for (j = 0; j < n; j++) if (b.test(j)) k++;
    int r = 0;
    for (j = 0; j < m; j++) if (b.test(x.at(j) - 1) && b.test(y.at(j) - 1)) r++;
    if (k * (k-1) / 2 == r) ret = max(ret, k);
  }
  cout << ret << endl;
}
