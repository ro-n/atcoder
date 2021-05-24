#include <iostream>
#include <set>
/* #include <pair> */
#include <utility>
#include <vector>

#define ll long long

using namespace std;

int main() {
  ll h, w, n;
  cin >> h >> w >> n;
  set<pair<ll, ll> > s;
  set<pair<ll, ll> > sa;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    pair<ll, ll> pos = make_pair(a, b);
    s.insert(pos);
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        sa.insert(make_pair(a+i, b+j));
      }
    }
  }

  vector<ll> sub(10, 0);

  for (pair<ll, ll> p: sa) {
    ll x = p.first, y = p.second;
    if (x < 2 || y < 2 || x + 1 > h || y + 1 > w) continue;

    ll cur = 0;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        cur += s.count(make_pair(x+i, y+j));
      }
    }
    sub[cur] += 1;
  }

  sub[0] = (h - 2) * (w - 2);
  for (int i = 1; i <= 9; i++) sub[0] -= sub[i];

  for (int i = 0; i < 10; i++) {
    cout << sub[i] << endl;
  }
  return 0;
}
