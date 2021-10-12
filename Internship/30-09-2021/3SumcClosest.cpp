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

int threeSumClosest(vector<int>& nums, int target) {
  int diff = INT_MAX, n = nums.size();
  int ans;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 2; i++) {
    bool found = false;
    int j = i + 1, k = n - 1;
    while (j < n - 1 && j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum == target) {
        ans = nums[i] + nums[j] + nums[k];
        found = true;
        break;
      } else if (sum > target) {
        k--;
        if (abs(diff) > abs(target - sum)) {
          diff = target - sum;
          ans = sum;
        }
      } else {
        j++;
        if (abs(diff) > abs(target - sum)) {
          diff = target - sum;
          ans = sum;
        }
      }
    }
    if (found) {
      break;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128};
  int target = 82;
  out threeSumClosest(nums, target) endl;

  return 0;
}