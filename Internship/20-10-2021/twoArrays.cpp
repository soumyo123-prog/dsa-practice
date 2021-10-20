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

int sumArray(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

void solve() {
  int n;
  in n;
  vector<int> a, b;
  initialize(a, n);
  initialize(b, n);

  vector<pair<int, int>> ans;

  if (sumArray(a, n) != sumArray(b, n)) {
    out - 1 endl;
  } else {
    while (a != b) {
      int i;
      for (i = 0; i < n; i++) {
        if (a[i] > b[i]) {
          break;
        }
      }

      int j;
      for (j = 0; j < n; j++) {
        if (a[j] < b[j]) {
          break;
        }
      }

      a[i]--;
      a[j]++;
      ans.pb(mp(i + 1, j + 1));
    }

    out ans.size() endl;
    for (int i = 0; i < ans.size(); i++) {
      out ans[i].first << ' ' << ans[i].second endl;
    }
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