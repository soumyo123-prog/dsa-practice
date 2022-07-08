#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &a) {
  int n = a.size();
  vector<int> b = a;
  int a1, a2;
  for (int i = 0; i < n; i++) {
    if (b[abs(b[i]) - 1] > 0) {
      b[abs(b[i]) - 1] = -b[abs(b[i]) - 1];
    } else {
      a1 = b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] > 0) {
      a2 = i + 1;
    }
  }
  return {a1, a2};
}

int main() { return 0; }