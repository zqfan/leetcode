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
    vector<Interval> merge(vector<Interval>& intervals) {
        auto cmp = [] (Interval & a, Interval & b) {return a.start < b.start;};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;
        for ( Interval & i : intervals ) {
            if ( result.empty() || result.back().end < i.start )
                result.push_back(i);
            else
                result.back().end = max(result.back().end, i.end);
        }
        return result;
    }
};
