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
  vector<int> a1, a2;
  initialize(a1, n);
  initialize(a2, n);

  bool flag = true;
  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());
  for (int i = 0; i < n; i++) {
    if (a2[i] - a1[i] < 0 || a2[i] - a1[i] > 1) {
      flag = false;
      break;
    }
  }

  flag ? out "YES" endl : out "NO" endl;
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