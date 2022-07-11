#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int a) {
  vector<vector<int>> result;
  for (int i = 0; i < a; i++) {
    vector<int> curr;
    curr.push_back(1);
    for (int j = 1; j <= i; j++) {
      curr.push_back((curr[j - 1] * (i - j + 1)) / j);
    }
    result.push_back(curr);
  }
  return result;
}

int main() { return 0; }