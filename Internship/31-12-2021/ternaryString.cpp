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

bool check(vint c1, vint c2, vint c3, int len, int n) {
  for (int i = 0; i + len - 1 < n; i++) {
    if (c1[i + len - 1] - (i == 0 ? 0 : c1[i - 1]) > 0 &&
        c2[i + len - 1] - (i == 0 ? 0 : c2[i - 1]) > 0 &&
        c3[i + len - 1] - (i == 0 ? 0 : c3[i - 1]) > 0) {
      return true;
    }
  }
  return false;
}

int solve() {
  string s;
  in s;
  int n = s.length();

  vint c1(n, 0), c2(n, 0), c3(n, 0);
  if (s[0] == '1')
    c1[0]++;
  else if (s[0] == '2')
    c2[0]++;
  else
    c3[0]++;

  rep(i, 1, n) {
    if (s[i] == '1') {
      c1[i] = c1[i - 1] + 1;
      c2[i] = c2[i - 1];
      c3[i] = c3[i - 1];
    } else if (s[i] == '2') {
      c1[i] = c1[i - 1];
      c2[i] = c2[i - 1] + 1;
      c3[i] = c3[i - 1];
    } else {
      c1[i] = c1[i - 1];
      c2[i] = c2[i - 1];
      c3[i] = c3[i - 1] + 1;
    }
  }

  int MAX = 2e5 + 1;
  int st = 3, en = s.length(), ans = MAX;
  while (st <= en) {
    int mid = st + (en - st) / 2;
    if (check(c1, c2, c3, mid, n)) {
      ans = mid;
      en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  if (ans == MAX) return 0;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    out solve() endl;
  }

  return 0;
}