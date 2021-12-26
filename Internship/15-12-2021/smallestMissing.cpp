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

int helper(vector<int> nums, int s, int e) {
  if (e < s) return e + 1;
  if (nums[s] > s) return s;

  int mid = s + (e - s) / 2;
  if (nums[mid] == mid) return helper(nums, mid + 1, e);
  return helper(nums, s, mid - 1);
}

int findSmallestMissingNumber(vector<int> const &nums) {
  return helper(nums, 0, nums.size() - 1);
}

void solve() {
  vint arr = {0, 1, 4, 5, 6, 7, 10};
  out findSmallestMissingNumber(arr) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}