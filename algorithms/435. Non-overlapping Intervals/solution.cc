/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int removes = 0, pre = INT_MIN;
        auto cmp = [] (const Interval & a, const Interval & b) {
            return a.end < b.end;
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for ( auto & i : intervals ) {
            if ( i.start < pre ) {
                ++removes;
            } else {
                pre = i.end;
            }
        }
        return removes;
    }
};
