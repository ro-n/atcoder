#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int s = stoi(str.substr(0, 4));
    int e = stoi(str.substr(5, 4));
    int s_ = s / 100 * 60 + s % 100;
    int e_ = e / 100 * 60 + e % 100;
    int _s = s_ / 5 * 5;
    int _e = (e_ + 4) / 5 * 5;
    v.push_back(make_pair(_s, _e));
  }
  sort(v.begin(), v.end()); // default first

  vector<pair<int, int>> ans;
  
  ans.insert(ans.end(), make_move_iterator(v.begin()),
      make_move_iterator(v.begin() + 1));
  // Iterators specifying a range of elements. Copies of the elements in the range [first,last) are inserted at position (in the same order).
  // https://www.cplusplus.com/reference/vector/vector/insert/
  v.erase(v.begin());


  for (int i = 0; i < v.size(); i++) {
    if (v[i].first > ans.back().second) {
      ans.push_back(make_pair(v[i].first, v[i].second));
    } else if (v[i].second > ans.back().second) {
      ans.back().second = v[i].second;
    }
  }

  for (auto e: ans) {
    printf("%02d%02d-%02d%02d\n", e.first / 60, e.first % 60,
        e.second / 60, e.second % 60);
  }
}
