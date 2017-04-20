class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [] (const pair<int, int> & a, const pair<int, int> & b) {
            return a.first != b.first ? a.first > b.first : a.second < b.second;
        };
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> result;
        for ( auto & p : people ) {
            result.insert(result.begin() + p.second, p);
        }
        return result;
    }
};

// 37 / 37 test cases passed.
// Status: Accepted
// Runtime: 59 ms
// beats 37.66%
