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
  int n, m;
  in n >> m;

  sint vul;
  int cnt[n] = {0};
  while (m--) {
    int u, v;
    in u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    vul.insert(u);
    cnt[u]++;
  }

  int q;
  in q;
  while (q--) {
    int a, b, c;
    in a;
    if (a == 1) {
      in b >> c;
      b--, c--;
      if (b > c) swap(b, c);
      vul.insert(b);
      cnt[b]++;
    } else if (a == 2) {
      in b >> c;
      b--, c--;
      if (b > c) swap(b, c);
      cnt[b]--;
      if (cnt[b] == 0 && vul.find(b) != vul.end()) {
        vul.erase(vul.find(b));
      }
    } else {
      out n - vul.size() endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}