#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int value) { val = value; }
};

vector<vector<int>> getAllTraversals(Node* root) {
  vector<vector<int>> result;
  vector<int> preorder, inorder, postorder;

  stack<pair<Node*, int>> st;
  st.push(make_pair(root, 1));
  pair<Node*, int> curr;
  while (!st.empty()) {
    curr = st.top();
    st.pop();
    if (curr.second == 1) {
      preorder.push_back(curr.first->val);
      curr.second++;
      st.push(curr);
      if (curr.first->left != NULL) {
        st.push(make_pair(curr.first->left, 1));
      }
    } else if (curr.second == 2) {
      inorder.push_back(curr.first->val);
      curr.second++;
      st.push(curr);
      if (curr.first->right != NULL) {
        st.push(make_pair(curr.first->right, 1));
      }
    } else {
      postorder.push_back(curr.first->val);
    }
  }

  result.push_back(preorder);
  result.push_back(inorder);
  result.push_back(postorder);
  return result;
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<vector<int>> result = getAllTraversals(root);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}