#include <iostream>
#include <vector>

using namespace std;

vector<bool> digit(10, true);

bool check(int n) {
  while (n > 0) {
    if (!digit[n%10]) return false;
    n /= 10;
  }
  return true;
}

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    digit[d] = false;
  }
  while (!check(N)) N++;
  cout << N << endl;
}
