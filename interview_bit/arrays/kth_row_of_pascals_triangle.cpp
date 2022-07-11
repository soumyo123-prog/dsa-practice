#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int a) {
  vector<int> ans;
  ans.push_back(1);
  for (int i = 1; i <= a; i++) {
    int curr = (ans[i - 1] * (a - i + 1)) / i;
    ans.push_back(curr);
  }
  return ans;
}

int main() {
  vector<int> ans = getRow(2);
  for (int i = 0; i <= 2; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}