#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {

  cout <<  setfill('0');

  int m;
  cin >> m;
  if (m < 100) {
    cout << setw(2) << 0 << endl;
  } else if (m >= 100 && m <= 5000) {
    cout << setw(2) << trunc(m*10/1000) << endl;
  } else if (m >= 6000 && m <= 30000) {
    cout << trunc(m/1000) + 50 << endl;
  } else if (m >= 35000 && m <= 70000) {
    cout << 80 + trunc((m/1000-30)/5) << endl;
  } else {
    cout << 89 << endl;
  }
}
