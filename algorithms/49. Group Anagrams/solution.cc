class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for ( auto & s : strs ) {
            string ss = s;
            sort(ss.begin(), ss.end());
            group[ss].push_back(s);
        }
        vector<vector<string>> result;
        for ( auto & p : group ) {
            result.push_back(p.second);
        }
        return result;
    }
};

// 100 / 100 test cases passed.
// Status: Accepted
// Runtime: 32 ms
// beats 70.31 %
