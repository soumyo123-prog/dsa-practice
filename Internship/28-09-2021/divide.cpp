#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vvi vector<vector<int>>
#define vi vector<int>

int divide(int dividend, int divisor) {
  if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
  }

  int sign = 1;
  if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
    sign = -1;
  }

  long long divid = abs(dividend);
  long long divis = abs(divisor);
  int ans = 0;
  while (divid >= divis) {
    divid -= divis;
    ans++;
  }
  return sign * ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  out divide(38, 1) endl;

  return 0;
}