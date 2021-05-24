#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;

  /* int ia, ib, ic; */
  /* ia = 0; */
  /* ib = 0; */
  /* ic = 0; */
  int is[3] = { 0, 0, 0 };
  vector<string> ss;
  ss.push_back(sa);
  ss.push_back(sb);
  ss.push_back(sc);

  int next = 0;

  while (ss[next].size() != is[next]) {
    int next_char = (ss[next])[is[next]] - 97;
    is[next] += 1;
    next = next_char;
  }

  switch (next) {
    case 0: cout << 'A' << endl; break;
    case 1: cout << 'B' << endl; break;
    case 2: cout << 'C' << endl; break;
  }
}
