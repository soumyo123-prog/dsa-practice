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

int gcd(int a, int b) {
  while (a != 0) {
    int tmp = a;
    a = b % a;
    b = tmp;
  }
  return b;
}

void solve() {
  int n;
  in n;
  vector<int> arr;
  initialize(arr, n);

  bool alleq = true;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      alleq = false;
      break;
    }
  }

  if (alleq) {
    out - 1 endl;
  } else {
    vector<int> allDiff;
    int mind = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] != arr[j]) {
          allDiff.push_back(abs(arr[j] - arr[i]));
        }
      }
    }

    int ans = allDiff[0];
    for (int i = 1; i < allDiff.size(); i++) {
      ans = gcd(ans, allDiff[i]);
    }
    out ans endl;
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