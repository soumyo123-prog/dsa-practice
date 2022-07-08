#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

bool isLeaf(Node* node) { return !node->left && !node->right; }

void leftTraversal(Node* root, vector<int>& res) {
  Node* curr = root;
  while (curr != NULL && !isLeaf(curr)) {
    res.push_back(curr->data);
    if (curr->left) {
      curr = curr->left;
    } else if (curr->right) {
      curr = curr->right;
    }
  }
}

void leafTraversal(Node* root, vector<int>& res) {
  if (root == NULL) {
    return;
  }
  if (isLeaf(root)) {
    res.push_back(root->data);
    return;
  }
  leafTraversal(root->left, res);
  leafTraversal(root->right, res);
}

void rightTraversal(Node* root, vector<int>& res) {
  Node* curr = root;
  stack<int> st;
  while (curr != NULL && !isLeaf(curr)) {
    st.push(curr->data);
    if (curr->right) {
      curr = curr->right;
    } else if (curr->left) {
      curr = curr->left;
    }
  }
  while (!st.empty()) {
    res.push_back(st.top());
    st.pop();
  }
}

vector<int> boundary(Node* root) {
  vector<int> res;
  if (root == NULL) {
    return res;
  }
  if (isLeaf(root)) {
    res.push_back(root->data);
    return res;
  }
  res.push_back(root->data);
  leftTraversal(root->left, res);
  leafTraversal(root, res);
  rightTraversal(root->right, res);
}

int main() { return 0; }