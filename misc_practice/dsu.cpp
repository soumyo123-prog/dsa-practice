#include <bits/stdc++.h>
using namespace std;

void makeSet(int n, vector<int> &parent, vector<int> &rank) {
  for (int i = 0; i < n; i++) {
    parent.push_back(i);
    rank.push_back(0);
  }
}

int findParent(int u, vector<int> &parent) {
  if (parent[u] == u) {
    return u;
  }
  return parent[u] = findParent(parent[u], parent);
}

void merge(int u, int v, vector<int> &parent, vector<int> &rank) {
  u = findParent(u, parent);
  v = findParent(v, parent);
  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[u] > rank[v]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}

int main() { return 0; }