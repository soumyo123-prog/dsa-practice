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

int cnt[2001];

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
  int q;
  in q;

  for (int i = 0; i < n; i++) {
    cnt[arr[i]]++;
  }

  vector<vector<int>> upto;
  upto.pb(arr);

  while (true) {
    vector<int> tmp;
    for (int j = 0; j < n; j++) {
      tmp.pb(cnt[arr[j]]);
    }

    if (tmp == arr) break;
    for (int j = 0; j < n; j++) {
      cnt[arr[j]] = 0;
    }
    for (int j = 0; j < n; j++) {
      cnt[tmp[j]]++;
    }
    upto.pb(tmp);
    arr = tmp;
  }

  while (q--) {
    int x, k;
    in x >> k;

    if (k > upto.size() - 1) {
      out upto[upto.size() - 1][x - 1] endl;
    } else {
      out upto[k][x - 1] endl;
    }
  }

  for (int i = 0; i < n; i++) {
    cnt[upto[upto.size() - 1][i]] = 0;
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