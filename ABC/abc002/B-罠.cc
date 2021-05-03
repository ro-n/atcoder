#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') continue;
    if (s[i] == 'i') continue;
    if (s[i] == 'u') continue;
    if (s[i] == 'e') continue;
    if (s[i] == 'o') continue;
    cout << s[i];
  }
  cout << endl;
}
