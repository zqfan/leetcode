class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int lus = -1;
        int i, j;
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < n; j++ ) {
                if ( i != j && is_subseq(strs[i], strs[j]) ) {
                    break;
                }
            }
            if ( j == n ) {
                lus = max(lus, (int)strs[i].size());
            }
        }
        return lus;
    }

    bool is_subseq(string s1, string s2) {
        int i = 0;
        for ( int j = 0; j < s2.size(); j++ ) {
            if ( i < s1.size() && s1[i] == s2[j] ) {
                i++;
            }
        }
        return i == s1.size();
    }
};
