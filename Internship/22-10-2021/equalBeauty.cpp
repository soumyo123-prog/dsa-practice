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
  int n;
  in n;
  vector<int> arr;
  initialize(arr, n);
  sort(arr.begin(), arr.end());

  int p = 0;

  if (n == 2) {
    out 0 endl;
  } else if (n == 3) {
    out min(arr[2] - arr[1], arr[1] - arr[0]) endl;
  } else {
    int d1 = arr[n - 1] - arr[0];
    int d2 = arr[n - 2] - arr[1];
    int ans = abs(d1 - d2);

    int a1 = INT_MAX;
    int p = 0;
    while (p <= n - 2) {
      int d1 = arr[p] - arr[0];
      int d2 = arr[n - 1] - arr[p + 1];
      a1 = min(a1, abs(d1 - d2));
      p++;
    }

    out min(ans, a1) endl;
  }
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