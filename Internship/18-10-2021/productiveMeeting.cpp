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
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.push_back(mp(x, i));
  }
  sort(arr.begin(), arr.end());

  int size = 0;
  vector<pair<pair<int, int>, int>> ans;

  if (arr.size() > 2) {
    int i1 = n - 2, i2 = n - 1;
    while (i1 < i2 && i1 >= 0) {
        }
  } else if (arr.size() == 2) {
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