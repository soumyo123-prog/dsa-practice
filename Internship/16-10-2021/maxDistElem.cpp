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
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(mp(x, i));
  }
  sort(arr.begin(), arr.end());

  vector<int> ans(n, 0);
  ans[arr[0].second] = 0;
  int rem = 1;

  for (int i = 1; i < n; i++) {
    if (rem >= arr[i].first) {
      ans[arr[i].second] = arr[i].first;
    } else {
      ans[arr[i].second] = rem;
      rem++;
    }
  }

  for (int i = 0; i < n; i++) {
    out ans[i] << ' ';
  }
  cout endl;
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