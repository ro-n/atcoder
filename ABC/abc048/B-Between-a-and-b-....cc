#include <iostream>

#define ll long long
using namespace std;

// https://img.atcoder.jp/arc064/editorial.pdf
ll f(ll inp, ll div) {
  if (inp >= 0) return inp/div + 1;
  else return 0;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  cout << f(b, c) - f(a-1, c) << endl;
}
