#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
  int n;
  ll t;
  cin >> n >> t;
  int pre;
  cin >> pre;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  int cur_max = 0;
  int max_cnt = 0;

  for (int i = 1; i < n; i++) {
    int cur;
    cin >> cur;
    if (cur > pre) {
      if (cur - pre == cur_max) max_cnt += 1;
      else if (cur - pre > cur_max) {
        max_cnt = 1;
        cur_max = cur - pre;
      }
    } else { // cur < pre
      pre = cur;
    }
  }

  /* t /= 2; */
  /* if (t >= max_cnt) { */
  /*   cout << max_cnt << endl; */
  /* } else { */
  /*   cout << max_cnt - t + 1 << endl; */
  /* } */
  cout << max_cnt << endl;
}
