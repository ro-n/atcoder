
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<string> dir = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

vector<int> range = {15, 93, 201, 327, 477, 645, 831, 1029, 1245, 1467, 1707, 1959, 12000};

// 15 = 2.5 * 60

int main() {
  int deg, dis;
  cin >> deg >> dis;
  deg = ((deg * 10 + 1125) / 2250) % 16;
  int i = 0;
  while (range[i] <= dis) i++;
  if (i == 0) {
    cout << "C 0" << endl;
  } else {
    cout << dir[deg] << " " << i << endl;
  }
  return 0;
}
