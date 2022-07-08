#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &a) {
  vector<pair<int, int>> arr;
  for (int i = 0; i < a.size(); i++) {
    arr.push_back(make_pair(a[i], i));
  }
  int n = arr.size();
  sort(arr.begin(), arr.end());

  vector<int> suff(n);
  suff[n - 1] = arr[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
    suff[i] = max(arr[i].second, suff[i + 1]);
  }

  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, suff[i + 1] - arr[i].second);
  }
  return ans;
}

int main() {
  vector<int> a = {0, 1, 2};
  cout << maximumGap(a) << endl;
  return 0;
}