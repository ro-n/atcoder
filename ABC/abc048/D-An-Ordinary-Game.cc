#include <iostream>
#include <string>

using namespace std;

/* const int MAX = 1e+05; */
/* bool removed[MAX]; */

int main() {
  string s;
  cin >> s;

  // action:
  // 0, 1, 2, ..., n
  // S, F, S, ..., .
  
  if (s[0] == s[s.size() - 1]) { // -> aba, ababa, abababa, ...
    if (s.size() & 1) cout << "Second" << endl;
    else cout << "First" << endl;
  } else { // -> ab, abab, ababab, ...
    if (s.size() & 1) cout << "First" << endl;
    else cout << "Second" << endl;

  }
}
