#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end(), greater<int>());
  double ret = 0;
  // 5, 4, 3, 2, 1
  // ret + 3 / 2 + 4 / 2 + 5 / 2
  /* for (int i = 0; i < k; i++) { */
  /*   ret += vec[i]; */
  /*   ret /= 2; */
  /* } */

  for (int i = k - 1; i >= 0; i--) {
    ret += vec[i];
    ret /= 2;
  }
  printf("%.9lf\n", ret);
}
