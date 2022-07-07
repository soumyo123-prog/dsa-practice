#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, b;
  cin >> n >> b;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  n = a.size();
  vector<int> pref(n, 0);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }
  int ans = pref[n - 1] - pref[n - b - 1];
  for (int i = 0; i < b; i++) {
    ans = max(ans, pref[i] + pref[n - 1] - pref[n - b + i]);
  }
  cout << ans << endl;

  return 0;
}