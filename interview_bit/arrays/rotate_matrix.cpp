#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &a) {
  int n = a.size(), c = n / 2;
  for (int i = 0; i < c; i++) {
    int x1 = i, x2 = i, x3 = n - i - 1, x4 = n - i - 1;
    int y1 = i, y2 = n - i - 1, y3 = n - i - 1, y4 = i;
    while (y1 < n - i - 1) {
      int a1 = a[x1][y1], a2 = a[x2][y2], a3 = a[x3][y3], a4 = a[x4][y4];
      a[x2][y2] = a1;
      a[x3][y3] = a2;
      a[x4][y4] = a3;
      a[x1][y1] = a4;
      y1++;
      x2++;
      y3--;
      x4--;
    }
  }
}

int main() { return 0; }