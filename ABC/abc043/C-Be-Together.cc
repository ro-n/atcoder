/* x = sum(b) / n */

#include <iostream>
#include <algorithm>

int a[100];
int n;

using namespace std;

int cal(int base) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += (base - a[i]) * (base - a[i]);
  }
  return ret;
}

int main() {
  cin >> n;
  int tol = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tol += a[i];
  } 
  int x = tol / n;
  cout << min(min(cal(x), cal(x+1)), cal(x-1)) << endl;
}

