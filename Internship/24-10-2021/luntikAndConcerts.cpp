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

void solve() {
  int a, b, c;
  in a >> b >> c;
  int diff = 0;

  if (a > 0 && b > 0) {
    int num = min(a, b);
    c %= num;
    b -= num;
    a -= num;

  } else if (b > 0) {
  } else {
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