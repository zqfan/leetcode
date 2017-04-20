class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> counter(256);
        for ( char c : s ) {
            ++counter[c].first;
            counter[c].second = c;
        }
        make_heap(counter.begin(), counter.end());
        string result;
        while ( counter.size() > 0 ) {
            pop_heap(counter.begin(), counter.end());
            result += string (counter.back().first, counter.back().second);
            counter.pop_back();
        }
        return result;
    }
};

// 35 / 35 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// beats 71.13%
