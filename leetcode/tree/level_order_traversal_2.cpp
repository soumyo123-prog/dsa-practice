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

int maxDepth(TreeNode *node) {
  if (node == NULL) return 0;
  return (1 + max(maxDepth(node->left), maxDepth(node->right)));
}

vector<vector<int>> levelOrderBottom(TreeNode *root) {
  int height = maxDepth(root);
  vector<vector<int>> result(height);
  if (root == NULL) {
    return result;
  }

  queue<TreeNode *> q;
  q.push(root);
  int cheight = 0;
  while (!q.empty()) {
    int len = q.size();
    vector<int> level;
    for (int i = 0; i < len; i++) {
      TreeNode *curr = q.front();
      q.pop();
      if (curr->left != NULL) {
        q.push(curr->left);
      }
      if (curr->right != NULL) {
        q.push(curr->right);
      }
      level.push_back(curr->val);
    }
    result[height - cheight - 1] = level;
    cheight++;
  }
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<vector<int>> levelOrder = levelOrderBottom(root);
  for (int i = 0; i < levelOrder.size(); i++) {
    for (int j = 0; j < levelOrder[i].size(); j++) {
      cout << levelOrder[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}