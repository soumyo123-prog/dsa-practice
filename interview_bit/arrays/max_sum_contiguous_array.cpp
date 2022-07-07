#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &a) {
  int sum = 0, ans = INT_MIN;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];
    ans = max(ans, sum);
    if (sum < 0) {
      sum = 0;
    }
  }
  return ans;
}

int main() {
  vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << maxSubArray(a) << endl;
  return 0;
}