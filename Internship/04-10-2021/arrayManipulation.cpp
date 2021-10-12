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

long long arrayManipulation(int n, vector<vector<int>> arr) {
  int m = arr.size();
  vector<int> t(n, 0);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int x = arr[i][0], y = arr[i][1], z = arr[i][2];
    t[x - 1] += z;
    if (y < n) {
      t[y] += z;
    }
  }
  for (int i = 0; i < n; i++) {
    if (t[i] > 0) {
      ans += t[i];
    }
  }
  return ans;
}

void solve() {
  int n, m;
  in n >> m;

  vector<vector<int>> q;
  for (int i = 0; i < m; i++) {
    vector<int> t;
    initialize(t, 3);
    q.pb(t);
  }

  out arrayManipulation(n, q) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}