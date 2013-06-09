/* Copyright 2013 <ZhiQiang Fan>

   Given a set of non-overlapping intervals, insert a new interval
   into the intervals (merge if necessary).

   You may assume that the intervals were initially sorted according
   to their start times.

   Example 1:
   Given intervals [1,3],[6,9], insert and merge [2,5] in as
   [1,5],[6,9].

   Example 2:
   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in
   as [1,2],[3,10],[12,16].

   This is because the new interval [4,9] overlaps with
   [3,5],[6,7],[8,10].
*/
#include <cstdio>
#include <vector>
using std::vector;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
  vector<Interval> insert(vector<Interval> &intervals,
                          Interval newInterval) {
    vector<Interval> result;
    int start, end, i, insert_status = 0;

    start = newInterval.start;
    end = newInterval.end;
    for (i = 0; i < intervals.size(); i++) {
      // no overlapping
      if (end < intervals[i].start || intervals[i].end < start) {
        // newInterval has been processed
        if (insert_status == 1 ||
            // newInterval is on the most left
            (insert_status == 0 && end < intervals[i].start)) {
          result.push_back(Interval(start, end));
          insert_status = 2;
        }
        result.push_back(intervals[i]);
        continue;
      }
      insert_status = 1;
      // with overlapping
      if (intervals[i].start <= end && end < intervals[i].end)
        end = intervals[i].end;
      if (intervals[i].start <= start && start <= intervals[i].end)
        start = intervals[i].start;
    }
    if (insert_status != 2)
      result.push_back(Interval(start, end));

    return result;
  }
};

int main() {
  int a[][2] = {{10, 10}};
  vector<Interval> intervals;
  int i;
  for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    intervals.push_back(Interval(a[i][0], a[i][1]));
  Solution s;
  vector<Interval> r = s.insert(intervals, Interval(4, 9));
  for (i = 0; i < r.size(); i++)
    printf("%d %d\n", r[i].start, r[i].end);
  return 0;
}
