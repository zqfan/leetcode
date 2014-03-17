/* Copyright 2013 <ZhiQiang Fan>

   Given a collection of intervals, merge all overlapping intervals.

   For example,
   Given [1,3],[2,6],[8,10],[15,18],
   return [1,6],[8,10],[15,18].
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
  bool static interval_less(Interval a, Interval b) {
    if (a.start != b.start)
      return a.start < b.start;
    else
      // a.end <= b.end will cause run time error when input is large
      // i don't know why
      return a.end < b.end;
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    int start, end, i;

    // invalid input
    if (intervals.size() < 1)
      return result;

    // it is evil to modify input, but i am Lucifer
    sort(intervals.begin(), intervals.end(), this->interval_less);

    start = intervals[0].start;
    end = intervals[0].end;
    for (i = 1; i < intervals.size(); i++) {
      if (end < intervals[i].start) {
        result.push_back(Interval(start, end));
        start = intervals[i].start;
        end = intervals[i].end;
      } else if (end < intervals[i].end) {
        end = intervals[i].end;
      }
    }
    result.push_back(Interval(start, end));

    return result;
  }
};

int main() {
  int a[][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<Interval> intervals;
  int i;
  for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    intervals.push_back(Interval(a[i][0], a[i][1]));
  Solution s;
  vector<Interval> r = s.merge(intervals);
  for (i = 0; i < r.size(); i++)
    printf("%d %d\n", r[i].start, r[i].end);
  return 0;
}
