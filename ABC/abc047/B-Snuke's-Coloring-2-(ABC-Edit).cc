#include <iostream>
#include <vector>

using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<vector<int> > v(w, vector<int>(h, 0));

  for (int i = 0; i < n; i++) {
    int xi, yi, ai;
    cin >> xi >> yi >> ai;
    switch (ai) {
      case (1):
        for (int j = 0; j < xi; j++) {
          for (int k = 0; k < h; k++) {
            v[j][k] = 1;
          }
        }
      break;
      case (2):
        for (int j = xi; j < w; j++) {
          for (int k = 0; k < h; k++) {
            v[j][k] = 1;
          }
        }
      break;
      case (3):
        for (int j = 0; j < w; j++) {
          for (int k = 0; k < yi; k++) {
            v[j][k] = 1;
          }
        }
      break;
      case (4):
        for (int j = 0; j < w; j++) {
          for (int k = yi; k < h; k++) {
            v[j][k] = 1;
          }
        }
      break;
    }
  }

  int ret = 0;
  for (int j = 0; j < w; j++) {
    for (int k = 0; k < h; k++) {
      if (v[j][k]) continue;
      ret += 1;
    }
  }

  cout << ret << endl;
}
