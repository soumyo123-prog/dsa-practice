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

struct Node {
  int data;
  Node *left, *right;
  Node *nextRight;
};

void connect(Node *root) {
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *t = q.front();
    Node *temp = q.front();
    q.pop();
    while (!q.empty()) {
      temp->nextRight = q.front();
      temp = temp->nextRight;
      q.pop();
    }
    temp->nextRight = NULL;

    while (t != NULL) {
      if (t->left) {
        q.push(t->left);
      }
      if (t->right) {
        q.push(t->right);
      }
      t = t->nextRight;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}