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
  int m, s;
  in m >> s;

  if (m == 1 && s == 0) {
    out 0 << ' ' << 0 endl;
  } else {
    if (s > 9 * m || s <= 0) {
      out - 1 << ' ' << -1 endl;
    } else {
      vector<char> str;
      str.pb('1');
      for (int i = 1; i < m; i++) {
        str.pb('0');
      }

      int sum = 1, i = m - 1;
      while (sum < s && i >= 0) {
        sum -= str[i] - '0';
        if (s - sum > 9) {
          sum += 9;
          str[i] = '9';
          i--;
        } else {
          int x = s - sum + '0';
          sum += (s - sum);
          str[i] = char(x);
          i--;
        }
      }

      for (int i = 0; i < str.size(); i++) {
        out str[i];
      }
      out ' ';

      for (int i = 0; i < m; i++) {
        str[i] = '9';
      }
      sum = 9 * m;
      i = m - 1;
      while (sum > s && i >= 0) {
        if (sum - s > 9) {
          sum -= 9;
          str[i] = '0';
          i--;
        } else {
          int x = s - (sum - 9) + '0';
          sum -= (sum - s);
          str[i] = char(x);
          i--;
        }
      }

      for (int i = 0; i < str.size(); i++) {
        out str[i];
      }
      cout endl;
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