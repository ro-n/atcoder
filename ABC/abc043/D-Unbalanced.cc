#include <iostream>
#include <string>

// https://www.quora.com/How-do-I-solve-Unbalanced-ARC059_D-on-AtCoder
// All we need to do is check if there is some  𝑖 , such that  𝑆[𝑖]=𝑆[𝑖+1] , or  𝑆[𝑖]=𝑆[𝑖+2] .

using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i+1]) {
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
  }
  for (int i = 0; i < s.size() - 2; i++) {
    if (s[i] == s[i+2]) {
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
