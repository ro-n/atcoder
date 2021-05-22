#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/* int compare(string a, string b) { */
/*   return a.compare(b); */
/* } */

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> con;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    con.push_back(s);
  }
  sort(con.begin(), con.end());
  for (int i = 0;i < N; i++) {
    cout << con[i];
  }
  cout << endl;
  return 0;
}
