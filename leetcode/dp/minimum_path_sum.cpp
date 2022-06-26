#include <bits/stdc++.h>
using namespace std;
#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pint;
typedef vector<vector<int>> vvint;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpint;
typedef vector<char> vchar;
typedef vector<string> vstring;
typedef map<int, int> mint;
typedef set<int> sint;

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
}

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << ' ';
  }
  cout endl;
}

int sumArray(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

void printYesOrNo(bool flag) {
  if (flag) {
    out "YES" endl;
  } else {
    out "NO" endl;
  }
}

int minPathSum(vector<vector<int>> &arr) {
  int n = arr.size(), m = arr[0].size();
  int dp[n][m];
  dp[n - 1][m - 1] = arr[n - 1][m - 1];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i == n - 1 && j == m - 1) continue;
      int s = INT_MAX;
      if (i + 1 < n) {
        s = min(s, arr[i][j] + dp[i + 1][j]);
      }
      if (j + 1 < m) {
        s = min(s, arr[i][j] + dp[i][j + 1]);
      }
      dp[i][j] = s;
    }
  }
  return dp[0][0];
}

void solve() {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  in t;
  while (t--) {
    solve();
  }
  return 0;
}

// ────────▓▓▓▓▓▓▓────────────▒▒▒▒▒▒
// ──────▓▓▒▒▒▒▒▒▒▓▓────────▒▒░░░░░░▒▒
// ────▓▓▒▒▒▒▒▒▒▒▒▒▒▓▓────▒▒░░░░░░░░░▒▒▒
// ───▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░░░░░░░░░░░▒
// ──▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▒
// ──▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒
// ─▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░▒
// ▓▓▒▒▒▒▒▒░░░░░░░░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒
// ▓▓▒▒▒▒▒▒▀▀▀▀▀███▄▄▒▒▒░░░▄▄▄██▀▀▀▀▀░░░░░░▒
// ▓▓▒▒▒▒▒▒▒▄▀████▀███▄▒░▄████▀████▄░░░░░░░▒
// ▓▓▒▒▒▒▒▒█──▀█████▀─▌▒░▐──▀█████▀─█░░░░░░▒
// ▓▓▒▒▒▒▒▒▒▀▄▄▄▄▄▄▄▄▀▒▒░░▀▄▄▄▄▄▄▄▄▀░░░░░░░▒
// ─▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒
// ──▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▒
// ───▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀▀░░░░░░░░░░░░░░▒
// ────▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒
// ─────▓▓▒▒▒▒▒▒▒▒▒▒▄▄▄▄▄▄▄▄▄░░░░░░░░▒▒
// ──────▓▓▒▒▒▒▒▒▒▄▀▀▀▀▀▀▀▀▀▀▀▄░░░░░▒▒
// ───────▓▓▒▒▒▒▒▀▒▒▒▒▒▒░░░░░░░▀░░░▒▒
// ────────▓▓▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░▒▒
// ──────────▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒
// ───────────▓▓▒▒▒▒▒▒▒▒░░░░░░░▒▒
// ─────────────▓▓▒▒▒▒▒▒░░░░░▒▒
// ───────────────▓▓▒▒▒▒░░░░▒▒
// ────────────────▓▓▒▒▒░░░▒▒
// ──────────────────▓▓▒░▒▒
// ───────────────────▓▒░▒
// ────────────────────▓▒