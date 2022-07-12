#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
vector<int> adj[MAX + 1];
bool vis[MAX + 1];

void dfs(int i, vector<int> &nums, int a, int b) {
  vis[i] = true;
  if (i >= a && i <= b) nums.push_back(i);
  if (i % 10 == 0 && i * 10 + i % 10 + 1 <= b) {
    adj[i].push_back(i * 10 + i % 10 + 1);
  } else if (i % 10 == 9 && i * 10 + i % 10 - 1 <= b) {
    adj[i].push_back(i * 10 + i % 10 - 1);
  } else if (i * 10 + i % 10 + 1 <= b) {
    adj[i].push_back(i * 10 + i % 10 - 1);
    adj[i].push_back(i * 10 + i % 10 + 1);
  }
  for (auto j : adj[i]) {
    if (!vis[j]) {
      dfs(j, nums, a, b);
    }
  }
}

vector<int> stepnum(int a, int b) {
  vector<int> nums;
  for (int i = 0; i <= 9; i++) {
    if (!vis[i]) {
      dfs(i, nums, a, b);
    }
  }
  return nums;
}

int main() {
  vector<int> nums = stepnum(10, 100);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << ' ';
  }
  cout << endl;
  return 0;
}