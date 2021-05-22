#include <iostream>

#define ll long long

using namespace std;

const ll MOD = 1e9+7;
const int N = 2e5+10;

ll fast_mod(ll input, ll ceil) {
  return input >= ceil ? input % ceil : input;
}

ll f[N];

ll qmod(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = fast_mod(ret * a, MOD);
    a = fast_mod(a * a, MOD);
    b >>= 1; 
  }
  return ret;
}

ll C(ll a, ll b) {
  return (f[a] * qmod(f[b]*f[a-b]%MOD, MOD-2)) % MOD;
}

const ll MAX = 100001;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  /* for (int i = 1; i <= h - a; i++) { */
  /*   for (int j = 1; j <= w; j++) { */
  /*     dp[i][j] = fast_mod(dp[i][j-1] + dp[i-1][j], MOD); */
  /*     cout << i << " " << j << " " << dp[i][j] << endl; */
  /*   } */
  /* } */
  /* for (int i = h - a + 1; i <= h; i++) { */
  /*   for (int j = b + 1; j <= w; j++) { */
  /*     dp[i][j] = fast_mod(dp[i][j-1] + dp[i-1][j], MOD); */
  /*     cout << i << " " << j << " " << dp[i][j] << endl; */
  /*   } */
  /* } */

  // m+n-2 C n-1 || m+n-2 C m-1
  
  f[0] = 1;
  for (ll i = 1; i < N; i++) f[i] = (f[i-1] * i) % MOD;

  ll res = 0;
  for (ll j = b + 1; j <= w; j++) {
    ll cur = (C(j+h-a-2, h-a-1)*C(w-j+a-1, w-j)) % MOD;
    res = (res + cur) % MOD;
  }
  cout << res << endl;
}


