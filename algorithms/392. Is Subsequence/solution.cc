class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> indices(26);
        for ( int i = 0; i < t.size(); ++i ) {
            indices[t[i] - 'a'].push_back(i);
        }
        for ( int pre = -1, i = 0; i < s.size(); ++i ) {
            auto & idx = indices[s[i] - 'a'];
            auto iter = upper_bound(idx.begin(), idx.end(), pre);
            if ( iter == idx.end() ) {
                return false;
            }
            pre = *iter;
        }
        return true;
    }
};
