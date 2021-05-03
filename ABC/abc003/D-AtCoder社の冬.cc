#include <iostream>

#define ll long long
using namespace std;

/* int binpow(int a, int b) { // recursive */
/*   if (b == 0) return 1; */
/*   int res = binpow(a, b / 2); */
/*   if (b % 2) return res * res * a; */
/*   else return res * res; */
/* } */

/* int binpow(int a, int b) { */
/*   int res = 1; */
/*   while (b > 0) { */
/*     if (b & 1) res = res * a; */
/*     a = a * a; */
/*     b >>= 1; */
/*   } */
/*   return res; */
/* } */

/* int binpow_MOD(int a, int b) { */
/*   int res = 1; */
/*   while (b > 0) { */
/*     if (b & 1) res = res * a % MOD; */
/*     a = a * a % MOD; */
/*     b >>= 1; */
/*   } */
/*   return res; */
/* } */

const ll MAX = 905;
const ll MOD = 1000000007;
ll Comb[MAX][MAX];

ll R, C, X, Y, D, L;

// https://stackoverflow.com/questions/33333363/built-in-mod-vs-custom-mod-function-improve-the-performance-of-modulus-op
ll fast_mod(ll input, ll ceil) {
  return input >= ceil ? input % ceil : input;
}

void composition_table() {
  for (ll i = 0; i < MAX; i++) {
    Comb[i][0] = 1;
    Comb[i][i] = 1;
  }
  for (ll i = 1; i < MAX; i++) {
    for (ll j = 1; j < MAX; j++) {
      Comb[i][j] = fast_mod(Comb[i-1][j] + Comb[i-1][j-1], MOD);
    }
  }
}

ll fit(ll h, ll w) {
  if (h <= 0 || w <= 0) return 0;
  return fast_mod(Comb[h*w][D+L] * Comb[D+L][D], MOD);
}

int main() {
  composition_table();
  cin >> R >> C >> X >> Y >> D >> L;

  // 求めたい数は N - ( | P ∨ Q ∨ R ∨ S | ) である
  // N - ( | P | + | Q | + | R | + | S | - | P ∧ Q | - | P ∧ R | - | P ∧ S | - | Q ∧ R | - | Q ∧ S | - | R ∧ S | + | P ∧ Q ∧ R | + | P ∧ Q ∧ S | + | P ∧ R ∧ S | + | Q ∧ R ∧ S | - | P ∧ Q ∧ R ∧ S | )
  ll ans = fit(X, Y);
  ans -= (fit(X-1, Y) * 2 + fit(X, Y-1) * 2);
  ans += (fit(X-1, Y-1) * 4 + fit(X-2, Y) + fit(X, Y-2));
  ans -= (fit(X-2, Y-1) * 2 + fit(X-1, Y-2) * 2);
  ans += fit(X-2, Y-2);

  cout << fast_mod(fast_mod(ans + MOD*8, MOD) * (R-X+1) * (C-Y+1), MOD) << endl;

}
