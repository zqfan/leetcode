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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> indices;
        for ( int i = 0; i < intervals.size(); ++i ) {
            indices[intervals[i].start] = i;
        }
        vector<int> result;
        for ( auto & i : intervals ) {
            auto p = indices.lower_bound(i.end);
            result.push_back(p == indices.end() ? -1 : p->second);
        }
        return result;
    }
};
