#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &a) {
  int n = a.size(), m = a[0].size();
  vector<vector<int>> m1(m, vector<int>(3, -1)), m2(m, vector<int>(3, -1));

  for (int i = 0; i < m; i++) {
    bool r = false, g = false, b = false;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 'r' && !r) {
        r = true;
        m1[i][0] = j;
      }
      if (a[j][i] == 'g' && !g) {
        g = true;
        m1[i][1] = j;
      }
      if (a[j][i] == 'b' && !b) {
        b = true;
        m1[i][2] = j;
      }
    }
    r = false, g = false, b = false;
    for (int j = n - 1; j >= 0; j--) {
      if (a[j][i] == 'r' && !r) {
        r = true;
        m2[i][0] = j;
      }
      if (a[j][i] == 'g' && !g) {
        g = true;
        m2[i][1] = j;
      }
      if (a[j][i] == 'b' && !b) {
        b = true;
        m2[i][2] = j;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    vector<vector<int>> bases;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (k == j) {
          continue;
        }
        int i1 = m1[i][j], i2 = m2[i][k], comp = 3 - j - k;
        if (i1 != -1 && i2 != -1 && i2 - i1 >= 1) {
          bases.push_back({comp, i1, i2});
        }
      }
    }
    for (int j = 0; j < bases.size(); j++) {
      int i1 = -1, i2 = -1, comp = bases[j][0];
      for (int k = m - 1; k > i; k--) {
        if (m1[k][comp] != -1) {
          i1 = k;
          break;
        }
      }
      for (int k = 0; k < i; k++) {
        if (m1[k][comp] != -1) {
          i2 = k;
          break;
        }
      }
      if (i1 != -1) {
        int br = bases[j][2] - bases[j][1] + 1;
        int hei = i1 - i + 1;
        int area = ceil((br * hei) / 2.0);
        ans = max(ans, area);
      }
      if (i2 != -1) {
        int br = bases[j][2] - bases[j][1] + 1;
        int hei = i - i2 + 1;
        int area = ceil((br * hei) / 2.0);
        ans = max(ans, area);
      }
    }
  }
  return ans;
}

int main() {
  vector<string> a = {"rrrrr", "rrrrg", "rrrrr", "bbbbb"};
  cout << solve(a) << endl;
  return 0;
}