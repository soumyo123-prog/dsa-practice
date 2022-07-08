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

int height(TreeNode *node, int &diameter) {
  if (node == NULL) {
    return 0;
  }
  int lh = height(node->left, diameter);
  int rh = height(node->right, diameter);
  diameter = max(diameter, 1 + lh + rh);
  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root) {
  if (root == NULL) return 0;
  int diameter = 0;
  height(root, diameter);
  return diameter;
}

int main() { return 0; }