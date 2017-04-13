class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> n;
        for ( int i = 0; i < s.size(); ++i ) {
            if ( m.find(s[i]) != m.end() && m[s[i]] != t[i] ) {
                return false;
            } else if ( n.find(t[i]) != n.end() && n[t[i]] != s[i] ) {
                return false;
            } else {
                m[s[i]] = t[i];
                n[t[i]] = s[i];
            }
        }
        return true;
    }
};
