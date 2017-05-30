class Solution {
    string getfp(const string & s) {
        string fp;
        int count[26] = {0};
        for ( char c : s ) {
            ++count[c - 'a'];
        }
        for ( int i = 0; i < 26; ++i ) {
            fp += "," + to_string(count[i]);
        }
        return fp;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> group;
        for ( int n = strs.size(), i = 0; i < n; ++i ) {
            string fp = getfp(strs[i]);
            group[fp].push_back(i);
        }
        vector<vector<string>> result;
        for ( auto & p : group ) {
            result.push_back(vector<string>());
            for ( auto & i : p.second ) {
                result.back().push_back(strs[i]);
            }
        }
        return result;
    }
};

// 100 / 100 test cases passed.
// Status: Accepted
// Runtime: 119 ms
// beats 4.65 %
