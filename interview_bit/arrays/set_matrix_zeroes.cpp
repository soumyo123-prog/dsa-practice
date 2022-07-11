#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &a) {
  int n = a.size(), m = a[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        a[i][0] = 2;
        a[0][j] = 2;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i][0] == 2) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != 2) {
          a[i][j] = 0;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    if (a[0][i] == 2) {
      for (int j = 0; j < n; j++) {
        a[j][i] = 0;
      }
    }
  }
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> a(r);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  setZeroes(a);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}