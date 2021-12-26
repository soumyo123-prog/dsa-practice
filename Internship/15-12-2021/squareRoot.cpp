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

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
  return;
}

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << " ";
  }
  cout endl;
  return;
}

int sumArray(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

int findIndex(vector<int> const &nums, int target) {
  int s = 0, e = nums.size() - 1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (nums[mid] == target) {
      return mid;
    } else {
      if (nums[mid] > nums[e]) {
        if (target >= nums[s] && target <= nums[mid]) {
          e = mid - 1;
        } else {
          s = mid + 1;
        }
      } else {
        if (target >= nums[mid] && target <= nums[e]) {
          s = mid + 1;
        } else {
          e = mid - 1;
        }
      }
    }
  }
  return -1;
}

void solve() {
  vint nums = {8, 9, 10, 2, 5, 6};
  int key;
  in key;
  out findIndex(nums, key) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}