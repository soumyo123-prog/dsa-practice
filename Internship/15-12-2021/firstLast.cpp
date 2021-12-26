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

int first(vector<int> nums, int key) {
  int s = 0, e = nums.size() - 1;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (nums[mid] == key) {
      ans = mid;
      e = mid - 1;
    } else if (nums[mid] > key) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return ans;
}

int last(vector<int> nums, int key) {
  int s = 0, e = nums.size() - 1;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (nums[mid] == key) {
      ans = mid;
      s = mid + 1;
    } else if (nums[mid] > key) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return ans;
}

pair<int, int> findPair(vector<int> const &nums, int target) {
  return make_pair(first(nums, target), last(nums, target));
}

void solve() {
  vint nums = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
  int key;
  in key;
  out findPair(nums, key).first << ' ' << findPair(nums, key).second endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}