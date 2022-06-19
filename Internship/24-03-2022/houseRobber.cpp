#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pint;
typedef vector<vector<int>> vvint;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpint;
typedef vector<char> vchar;
typedef vector<string> vstring;
typedef map<int, int> mint;
typedef set<int> sint;

int rob(vector<int> &nums) {
  int n = nums.size();
  if (n == 0) return 0;
  if (n == 1) return nums[0];

  int dp[n];
  dp[0] = nums[0];
  dp[1] = nums[1];

  int ans = max(dp[0], dp[1]);
  for (int i = 2; i < n; i++) {
    dp[i] = 0;
    for (int j = i - 2; j >= 0; j--) {
      dp[i] = max(dp[i], nums[i] + dp[j]);
    }
    ans = max(ans, dp[i]);
  }

  return ans;
}

void solve() {
  vint nums = {1, 2, 3, 1};
  out rob(nums) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}