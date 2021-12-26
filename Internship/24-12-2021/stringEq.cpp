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

void solve() {
  int n, k;
  in n >> k;
  string a, b, no = "No", yes = "Yes";
  in a >> b;

  int c1[26] = {0}, c2[26] = {0};
  rep(i, 0, n) {
    c1[a[i] - 'a']++;
    c2[b[i] - 'a']++;
  }

  bool flag = true;
  rep(i, 0, 25) {
    if (c1[i] < c2[i] || c1[i] - c2[i] % k != 0) {
      flag = false;
      break;
    }
    c1[i + 1] += c1[i];
  }

  if (flag)
    out yes endl;
  else
    out no endl;
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