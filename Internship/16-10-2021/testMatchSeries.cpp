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

string ind = "INDIA", eng = "ENGLAND", dr = "DRAW";

void solve() {
  int c1 = 0, c2 = 0, c3 = 0;

  for (int i = 0; i < 5; i++) {
    int x;
    in x;
    if (x == 1) {
      c1 += 1;
    } else if (x == 2) {
      c2++;
    } else {
      c3++;
    }
  }

  if (c1 > c2) {
    out ind endl;
  } else if (c1 < c2) {
    out eng endl;
  } else {
    out dr endl;
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