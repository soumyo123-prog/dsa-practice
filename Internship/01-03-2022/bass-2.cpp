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

int maxProfit(vector<int> &p) {
  int n = p.size();

  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (p[i + 1] > p[i]) {
      ans += p[i + 1] - p[i];
    }
  }
  return ans;
}

void solve() {
  vint prices = {1, 2, 3, 4, 5};
  out maxProfit(prices) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}