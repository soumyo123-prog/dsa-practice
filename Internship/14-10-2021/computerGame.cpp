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
  int n;
  in n;

  int arr[2][n];
  for (int i = 0; i < 2; i++) {
    string s;
    in s;
    for (int j = 0; j < n; j++) {
      arr[i][j] = s[j] - '0';
    }
  }

  string yes = "YES", no = "NO";

  int row = 0, col = 0;
  while (col < n - 1) {
    if (arr[0][col + 1] == 0 || arr[1][col + 1] == 0) {
      col++;
    } else {
      break;
    }
  }

  if (col == n - 1) {
    out yes endl;
  } else {
    out no endl;
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