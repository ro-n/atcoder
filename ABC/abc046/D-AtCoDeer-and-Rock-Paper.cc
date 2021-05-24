#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int g = 0, p = 0;
  int score = 0;
  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case 'g':
        if (g - p >= 1) {
          p += 1;
          score += 1;
        } else {
          g += 1;
        }
      break;
      case 'p':
      if (g - p >= 1) {
        p += 1;
      } else {
        g += 1;
        score -= 1;
      }
      break;
    }
  }
  cout << score << endl;
}
