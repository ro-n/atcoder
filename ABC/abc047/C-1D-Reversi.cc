#include <iostream>
#include <string>

using namespace std;



int main() {
  string s;
  cin >> s;
  
  int ret = 0;
  for (int i = 0, j; i < s.size(); i = j) {
    j = i;
    while (j < s.size() && s[i] == s[j]) j += 1;
    if (j == s.size()) break;
    ret += 1; 
  }

  cout << ret << endl;
}
