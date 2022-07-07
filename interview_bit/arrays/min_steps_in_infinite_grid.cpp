#include <bits/stdc++.h>
using namespace std;

int coverPoints(vector<int> &a, vector<int> &b) {
  int n = a.size(), ans = 0;
  for (int i = 1; i < n; i++) {
    int x1 = a[i - 1], x2 = a[i], y1 = b[i - 1], y2 = b[i];
    int xd = abs(x1 - x2), yd = abs(y1 - y2);
    if (xd > yd) {
      ans += yd + (xd - yd);
    } else {
      ans += xd + (yd - xd);
    }
  }
  return ans;
}

int main() { return 0; }