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

const int MAX = 2e5 + 1;
int l1[MAX + 1], l2[MAX + 1];

bool check(int cost, vint c0, vint c1, int n) {
  bool a1 = false, a2 = false;

  for (int i = 0; i < n; i++) {
    if (c0[i] >= cost) {
      int diff = c0[i] - cost;
      int c = c1[n - 1] - c1[i];
      if (diff > 0) {
        int ind = l1[diff];
        c += c1[ind];
      }
      if (c <= cost) {
        a1 = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (c1[i] <= cost) {
      int diff = cost - c1[i];
      int c = 0;
      int ind = l2[diff];
      if (ind != -1) {
        c += c0[ind] - c0[i];
        if (c <= cost) {
          a2 = true;
          break;
        }
      }
    }
  }

  return a1 || a2;
}

void solve() {
  string s;
  in s;
  int n = s.length();

  if (n == 1) {
    out 0 endl;
  } else {
    vint c0(n, 0), c1(n, 0);
    if (s[0] == '0') {
      c0[0] = 1;
    } else {
      c1[0] = 1;
    }
    for (int i = 1; i < n; i++) {
      if (s[i] == '0') {
        c0[i] = c0[i - 1] + 1;
        c1[i] = c1[i - 1];
      } else {
        c1[i] = c1[i - 1] + 1;
        c0[i] = c0[i - 1];
      }
    }

    for (int i = 0; i < n; i++) {
      if (i > 0 && c0[i] > c0[i - 1]) {
        l1[c0[i]] = i;
      }
      if (i > 0 && c1[i] > c1[i - 1]) {
        l2[c1[n - 1] - c1[i]] = i;
      }
    }

    int st = 0, en = max(c1[n - 1], c0[n - 1]), ans = en;
    while (st <= en) {
      int mid = (st + (en - st) / 2);
      if (check(mid, c0, c1, n)) {
        en = mid - 1;
        ans = min(ans, mid);

      } else {
        st = mid + 1;
      }
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