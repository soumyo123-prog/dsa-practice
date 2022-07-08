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

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> result;
  if (root == NULL) {
    return result;
  }

  queue<TreeNode *> q;
  q.push(root);
  bool ltr = true;

  while (!q.empty()) {
    int len = q.size();
    vector<int> level(len);
    for (int i = 0; i < len; i++) {
      TreeNode *curr = q.front();
      q.pop();
      if (curr->left != NULL) {
        q.push(curr->left);
      }
      if (curr->right != NULL) {
        q.push(curr->right);
      }
      if (!ltr) {
        level[len - i - 1] = curr->val;
      } else {
        level[i] = curr->val;
      }
    }
    if (!ltr) {
      ltr = true;
    } else {
      ltr = false;
    }
    result.push_back(level);
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

  vector<vector<int>> zigZag = zigzagLevelOrder(root);
  for (int i = 0; i < zigZag.size(); i++) {
    for (int j = 0; j < zigZag[i].size(); j++) {
      cout << zigZag[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}