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

int height(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int lh = height(root->left);
  int rh = height(root->right);
  if (lh == -1 || rh == -1) {
    return -1;
  }
  if (abs(lh - rh) >= 2) {
    return -1;
  }
  return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode *root) { return height(root->left) != -1; }

int main() { return 0; }