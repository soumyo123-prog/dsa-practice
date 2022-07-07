#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a) {
  int n = a.size();
  vector<pair<int, int>> arr(n, make_pair(-1, -1));

  set<int> s1, s2;
  for (int i = 0; i < n; i++) {
    s1.insert(a[i]);
    auto it = s1.lower_bound(a[i]);
    if (it != s1.begin()) {
      it--;
      arr[i].first = *it;
    }
  }
  s2.insert(a[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    if (*s2.rbegin() > a[i]) {
      arr[i].second = *s2.rbegin();
    }
    s2.insert(a[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].first != -1 && arr[i].second != -1) {
      ans = max(ans, arr[i].first + a[i] + arr[i].second);
    }
  }
  return ans;
}

int main() {
  vector<int> a = {2, 5, 3, 1, 4, 9};
  cout << solve(a) << endl;
  return 0;
}