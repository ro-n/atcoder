#include <iostream>

using namespace std;

int main() {
  string s, t, r = "atcoder";
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '@')
      for (int j = 0; j < 7; j++)
        if (t[i] == r[j]) s[i] = t[i];
    if (t[i] == '@')
      for (int j = 0; j < 7; j++)
        if (s[i] == r[j]) t[i] = s[i];
  }
  cout << (s == t ? "You can win" : "You will lose") << endl;
}
