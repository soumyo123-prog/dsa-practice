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
  int arr[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      in arr[i][j];
    }
  }

  string ans = "NO";
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
      for (int k = 0; k < n; k++) {
        if (arr[k][i] == 1 && arr[k][j] == 1) {
          v3++;
        } else if (arr[k][i] == 1 && arr[k][j] == 0) {
          v1++;
        } else if (arr[k][i] == 0 && arr[k][j] == 1) {
          v2++;
        } else {
          v4++;
        }
      }

      if (v4 > 0) {
        continue;
      }
      if (v1 > n / 2 || v2 > n / 2) {
        continue;
      }
      ans = "YES";
      break;
    }
    if (ans == "YES") {
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