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

  int cnt = 0;
  string ans = "YES";
  for (int i = 0; i < n; i++) {
    int j;
    for (j = 0; j <= cnt; j++) {
      if (arr[i] % (i - j + 2) != 0) {
        cnt++;
        break;
      }
    }
    if (j > cnt) {
      ans = "NO";
      break;
    }
  }

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