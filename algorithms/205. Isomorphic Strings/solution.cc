class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m [256] = { 0 }, n [256] = { 0 }, l = s.size();
        for ( int i = 0; i < l; ++i ) {
            if ( m[s[i]] != n[t[i]] ) {
                return false;
            }
            m[s[i]] = n[t[i]] = i + 1;
        }
        return true;
    }
};
