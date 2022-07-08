#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int helper(TreeNode *node, int &maxTillNow) {
  if (node == NULL) return 0;
  int left = max(0, helper(node->left, maxTillNow));
  int right = max(0, helper(node->right, maxTillNow));
  maxTillNow = max(maxTillNow, node->val + left + right);
  return node->val + max(left, right);
}

int maxPathSum(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int maxTillNow = INT_MIN;
  helper(root, maxTillNow);
  return maxTillNow;
}

int main() { return 0; }