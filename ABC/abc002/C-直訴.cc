#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  long double x1, y1;
  long double x2, y2;
  long double x3, y3;

  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;

  cout << fixed << setprecision(10);
  cout << abs((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3)) / 2 << endl;
} 
