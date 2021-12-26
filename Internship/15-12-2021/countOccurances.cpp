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

int helper(vector<int> nums, int key, int s, int e) {
  if (s > e) return 0;

  int mid = s + (e - s) / 2;
  if (nums[mid] == key) {
    return 1 + helper(nums, key, s, mid - 1) + helper(nums, key, mid + 1, e);
  } else if (nums[mid] > key) {
    return helper(nums, key, s, mid - 1);
  } else {
    return helper(nums, key, mid + 1, e);
  }
}

int countOccurrences(vector<int> const &nums, int target) {
  return helper(nums, target, 0, nums.size() - 1);
}

void solve() {
  int key;
  in key;
  vint arr = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
  out countOccurrences(arr, key) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}