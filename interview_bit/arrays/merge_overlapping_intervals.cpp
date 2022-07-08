#include <bits/stdc++.h>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval a, Interval b) { return a.start <= b.start; }

vector<Interval> merge(vector<Interval> &a) {
  int n = a.size();
  vector<Interval> result;
  if (n == 0) {
    return result;
  }

  sort(a.begin(), a.end(), comp);
  result.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    Interval curr = *result.rbegin();
    result.pop_back();
    if (a[i].start <= curr.end) {
      curr.end = max(a[i].end, curr.end);
      result.push_back(curr);
    } else {
      result.push_back(curr);
      result.push_back(a[i]);
    }
  }
  return result;
}

int main() { return 0; }