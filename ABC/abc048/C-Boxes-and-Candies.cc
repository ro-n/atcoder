#include <iostream>
#define ll long long

using namespace std;

int main() {
  ll n, x;
  cin >> n >> x;
  ll cur, prev;
  cin >> prev;
  ll ans = 0;
  for (ll i = 2; i <= n; i++) {
    cin >> cur;
    ll cnt = 0;
    if (cur + prev > x) {
      ll sub = cur + prev - x; // cur <= sub - cur
      if (cur > sub) {
        cur -= sub;
        cnt += sub;
      } else {
        sub -= cur;
        cnt += cur;
        cur = 0;

        prev -= sub;
        cnt += sub;
      }
    }
    ans += cnt;
    prev = cur;
  }
  cout << ans << endl;
}

