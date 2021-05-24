#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int ret = 1;
  for (int i = 1; i <= n; i++) {
    if (i == 1) ret *= k;
    else ret *= (k - 1);
  }

  cout << ret << endl;
  return 0;
}
