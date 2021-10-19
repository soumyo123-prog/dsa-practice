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
  int n, m, k;
  in n >> m >> k;

  bool pot[n][m];
  for (int i = 0; i < n; i++) {
    memset(pot[i], false, sizeof(pot[i]));
  }

  string board[n];
  for (int i = 0; i < n; i++) {
    in board[i];
  }

  for (int i = k; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '*') {
        int lh = 0, rh = 0;
        int x = i - 1, y = j - 1;
        while (x >= 0 && y >= 0 && board[x][y] == '*') {
          lh++;
          x--;
          y--;
        }
        x = i - 1;
        y = j + 1;
        while (x >= 0 && y < m && board[x][y] == '*') {
          rh++;
          x--;
          y++;
        }
        if (min(lh, rh) >= k) {
          int t = 1;
          int y1 = j - 1, y2 = j + 1;
          while (t <= min(lh, rh)) {
            pot[i - t][y1] = true;
            pot[i - t][y2] = true;
            y1--;
            y2++;
            t++;
          }
          pot[i][j] = true;
        }
      }
    }
  }

  string ans = "YES";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '*' && !pot[i][j]) {
        ans = "NO";
        break;
      }
    }
    if (ans == "NO") {
      break;
    }
  }
  out ans endl;
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