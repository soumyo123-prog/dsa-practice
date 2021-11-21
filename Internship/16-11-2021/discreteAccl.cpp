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

void fill(vector<int> arr, vector<double> &time1, vector<double> &time2, int n,
          int l) {
  int s1 = 1, s2 = 1;
  double t1 = arr[0], t2 = l - arr[n - 1];
  time1[0] = t1;
  time2[n - 1] = t2;

  for (int i = 1; i < n; i++) {
    s1++;
    s2++;
    t1 += double(arr[i] - arr[i - 1]) / s1;
    time1[i] = t1;

    int j = n - i - 1;
    t2 += double(arr[j + 1] - arr[j]) / s2;
    time2[j] = t2;
  }
}

void solve() {
  int n, l;
  in n >> l;
  vector<int> arr;
  initialize(arr, n);

  vector<double> time1(n, 0), time2(n, 0);
  fill(arr, time1, time2, n, l);

  int idx = 0;
  while (idx < n && time1[idx] < time2[idx]) {
    idx++;
  }

  double t1, t2, x, ans, s1, s2;
  if (idx == 0) {
    s1 = 1;
    s2 = n + 1;
    t1 = 0;
    t2 = time2[idx] + double(arr[0]) / double(n + 1);
  } else {
    idx--;
    s1 = idx + 2;
    s2 = (n - idx - 1) + 1;
    t1 = time1[idx];
    t2 = time2[idx];
  }
  x = double(s2 * s1 * (t2 - t1)) / double(s2 + s1);
  ans = double(s1 * t1 + x) / s1;

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