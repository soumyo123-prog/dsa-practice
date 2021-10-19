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

void solve() {
  int n;
  in n;
  vector<pair<int, int>> vt;

  for (int i = 0; i < n; i++) {
    int k;
    in k;
    int b = INT_MIN;
    for (int j = 0; j < k; j++) {
      int a;
      in a;
      b = max(b, a - j);
    }
    vt.pb(mp(b, k));
  }

  sort(vt.begin(), vt.end());
  int m = INT_MIN, sum = 0;

  for (int i = 0; i < n; i++) {
    m = max(m, vt[i].first - sum);
    sum += vt[i].second;
  }

  out m + 1 endl;
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