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

void sortFun(vector<int> &v) {
  if (v[1] < v[0]) {
    swap(v[0], v[1]);
  }
  if (v[2] < v[1]) {
    swap(v[1], v[2]);
    if (v[1] < v[0]) {
      swap(v[0], v[1]);
    }
  }
}

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> ans;
  if (nums.size() < 3) {
    return ans;
  }

  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 2; i++) {
    int s = i + 1, e = nums.size() - 1, r = nums.size() - 1;
    while (s < e && r > s) {
      if (nums[i] + nums[s] + nums[r] == 0) {
        vector<int> sorted = {nums[i], nums[s], nums[r]};
        sortFun(sorted);
        ans.push_back(sorted);
        while (r != 0 && nums[r] == nums[r - 1]) {
          r--;
        }
        while (s != e && nums[s] == nums[s + 1]) {
          s++;
        }
        s++;
        r--;
      } else if (nums[i] + nums[s] + nums[r] < 0) {
        s++;
      } else {
        r--;
      }
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  vector<vector<int>> ans = threeSum(nums);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      out ans[i][j] << ' ';
    }
    cout endl;
  }

  return 0;
}