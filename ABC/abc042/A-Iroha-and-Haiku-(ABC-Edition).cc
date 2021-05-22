#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> p;
  int A;
  int B;
  int C;
  cin >> A >> B >> C;
  p.push_back(A);
  p.push_back(B);
  p.push_back(C);
  sort(p.begin(), p.end());
  if (p[0] == 5 && p[1] == 5 && p[2] == 7) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
