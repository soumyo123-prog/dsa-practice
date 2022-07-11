#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &a) {
  vector<vector<int>> result;
  int i = 0, j = 0, n = a.size();
  while (j < n) {
    int x = 0, y = j;
    vector<int> curr;
    while (x < n && y >= 0) {
      curr.push_back(a[x][y]);
      x++;
      y--;
    }
    result.push_back(curr);
    j++;
  }
  j--;
  i++;
  while (i < n) {
    int x = i, y = n - 1;
    vector<int> curr;
    while (x < n && y >= 0) {
      curr.push_back(a[x][y]);
      x++;
      y--;
    }
    result.push_back(curr);
    i++;
  }
  return result;
}

int main() { return 0; }