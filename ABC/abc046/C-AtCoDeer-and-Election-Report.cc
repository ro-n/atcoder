#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;
  ll vt, va;
  cin >> vt >> va;
  for (int i = 2; i <= n; i++) {
    ll p1, p2;
    cin >> p1 >> p2;
    ll fac = max(vt/p1, va/p2);
    if (fac * p1 < vt || fac * p2 < va) fac += 1;
    vt = p1 * fac;
    va = p2 * fac;
  }
  cout << vt + va << endl;
}

