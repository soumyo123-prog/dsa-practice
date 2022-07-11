#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int a) {
  vector<vector<int>> result(a, vector<int>(a, -1));
  int num = 1, i = 0, j = 0;
  while (num <= a * a) {
    while (j < a && result[i][j] == -1) {
      result[i][j] = num;
      num++;
      j++;
    }
    j--;
    i++;
    while (i < a && result[i][j] == -1) {
      result[i][j] = num;
      num++;
      i++;
    }
    i--;
    j--;
    while (j >= 0 && result[i][j] == -1) {
      result[i][j] = num;
      num++;
      j--;
    }
    j++;
    i--;
    while (i >= 0 && result[i][j] == -1) {
      result[i][j] = num;
      num++;
      i--;
    }
    j++;
    i++;
  }
  return result;
}

int main() { return 0; }