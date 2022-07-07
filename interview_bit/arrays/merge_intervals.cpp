#include <bits/stdc++.h>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &arr, Interval newInterval) {
  int n = arr.size();
  vector<Interval> ans;

  if (n == 0) {
    ans.push_back(newInterval);
    return ans;
  }

  if (newInterval.start > arr[n - 1].end) {
    arr.push_back(newInterval);
    return arr;
  }

  if (newInterval.end < arr[0].start) {
    ans.push_back(newInterval);
    for (int i = 0; i < n; i++) {
      ans.push_back(arr[i]);
    }
    return ans;
  }

  int i1 = -1, i2 = -1;
  for (int i = 0; i < n; i++) {
    if (newInterval.start >= arr[i].start && newInterval.start <= arr[i].end) {
      i1 = i;
      break;
    }
    if (i + 1 < n && newInterval.start > arr[i].end &&
        newInterval.start < arr[i + 1].start) {
      i1 = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (newInterval.end >= arr[i].start && newInterval.end <= arr[i].end) {
      i2 = i;
      break;
    }
    if (i + 1 < n && newInterval.end > arr[i].end &&
        newInterval.end < arr[i + 1].start) {
      i2 = i;
      break;
    }
  }

  Interval mid;
  if (i1 == -1) {
    mid.start = newInterval.start;
  } else {
    for (int i = 0; i < i1; i++) {
      ans.push_back(arr[i]);
    }
    if (newInterval.start > arr[i1].end) {
      ans.push_back(arr[i1]);
      mid.start = newInterval.start;
    } else {
      mid.start = arr[i1].start;
    }
  }

  stack<Interval> st;
  if (i2 == -1) {
    mid.end = newInterval.end;
  } else {
    for (int i = n - 1; i > i2; i--) {
      st.push(arr[i]);
    }
    if (newInterval.end > arr[i2].end) {
      mid.end = newInterval.end;
    } else {
      mid.end = arr[i2].end;
    }
  }

  ans.push_back(mid);
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}

int main() {
  vector<Interval> arr;
  Interval interval = Interval(1, 1);
  vector<Interval> ans = insert(arr, interval);
  return 0;
}