#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
  vector<int> result(V, INT_MAX);
  result[S] = 0;

  set<pair<int, int>> st;
  st.insert(make_pair(0, S));

  while (!st.empty()) {
    pair<int, int> p = *(st.begin());
    st.erase(st.begin());

    int u = p.second;
    for (auto i : adj[u]) {
      int v = i[0], wt = i[1];
      if (result[v] > result[u] + wt) {
        if (result[v] != INT_MAX) {
          st.erase(st.find(make_pair(result[v], v)));
        }
        result[v] = result[u] + wt;
        st.insert(make_pair(result[v], v));
      }
    }
  }

  return result;
}

int main() { return 0; }