#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &a) {
  int c = 1, idx = 0, n = a.size();
  while (idx < n && a[idx] == 0) {
    idx++;
  }
  vector<int> inp(a.begin() + idx, a.begin() + n);
  n = inp.size();

  for (int i = n - 1; i >= 0; i--) {
    if (c == 0) {
      break;
    }
    int sum = c + inp[i];
    inp[i] = sum % 10;
    c = sum / 10;
  }

  if (c == 0) {
    return inp;
  }
  inp.insert(inp.begin(), c);
  return inp;
}

int main() { return 0; }