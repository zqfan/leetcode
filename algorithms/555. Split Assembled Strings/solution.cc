class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string result;
        vector<string> maxstrs;
        for ( int i = 0; i < strs.size(); ++i ) {
            string r(strs[i].rbegin(), strs[i].rend());
            maxstrs.push_back(max(strs[i], r));
        }
        for ( int i = 0; i < strs.size(); ++i ) {
            string mid;
            for ( int j = i + 1; j < strs.size(); ++j ) {
                mid += maxstrs[j];
            }
            for ( int j = 0; j < i; ++j ) {
                mid += maxstrs[j];
            }
            for ( int j = 0; j < strs[i].size(); ++j ) {
                result = max(result, strs[i].substr(j) + mid + strs[i].substr(0, j));
            }
            string r(strs[i].rbegin(), strs[i].rend());
            for ( int j = 0; j < strs[i].size(); ++j ) {
                result = max(result, r.substr(j) + mid + r.substr(0, j));
            }
        }
        return result;
    }
};
