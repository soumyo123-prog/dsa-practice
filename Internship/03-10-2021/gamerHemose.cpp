#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vvi vector<vector<int>>
#define vi vector<int>

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
  return;
}

void solve() {
  int n, h;
  in n >> h;

  vector<int> arr;
  initialize(arr, n);
  sort(arr.begin(), arr.end());

  int i1 = arr[n - 1], i2 = arr[n - 2];
  int ans;
  if (i1 >= h) {
    ans = 1;
  } else {
    ans = 2 * (h / (i1 + i2));
    if (h % (i1 + i2) > i1) {
      ans += 2;
    } else if (h % (i1 + i2) <= i1 && h % (i1 + i2) > 0) {
      ans += 1;
    }
  }

  out ans endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    solve();
  }

  return 0;
}