#include <iostream>
#include <string>

#define ll long long

using namespace std;

ll l2c[11] = { 1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

int main() {
  string str;
  cin >> str;

  ll ret = 0;
  for (int len = 1; len <= str.size(); len++) {
    for (int i = 0; i + len - 1 < str.size(); i++) {
      int s = i;
      int e = i + len - 1;
      string cstr = str.substr(s, len);
      ll cint = stoll(cstr);

      int llen = s - 0;
      int rlen = (str.size()-1) - e;

      ret += cint * l2c[llen] * l2c[rlen];
    }
  }
  cout << ret << endl;

}
