#include <iostream>
#include <string>

using namespace std;

int main() {
  string inp;
  cin >> inp;
  string out = "";
  for (int i = 0; i < inp.size(); i++) {
    if (inp[i] == '0' || inp[i] == '1') {
      out.append(string(1, inp[i]));
      continue;
    } else {
      if (out.size() == 0) continue;
      out.pop_back();
    }
  }
  cout << out << endl;
}
