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

void solve() {
  int l1, r1, l2, r2;
  in l1 >> r1 >> l2 >> r2;

  if (l2 > r1) {
    out l2 + l1 endl;
  } else if (l2 <= r1 && l2 >= l1) {
    out l2 endl;
  } else if (l2 < l1) {
    if (r2 >= r1) {
      out l1 endl;
    } else if (r2 < r1 && r2 >= l1) {
      out l1 endl;
    } else {
      out l1 + l2 endl;
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