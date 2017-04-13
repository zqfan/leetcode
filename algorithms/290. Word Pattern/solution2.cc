class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p;
        unordered_map<string, int> w;
        int n = pattern.size(), m = str.size(), j = 0;
        string word;
        for ( int i = 0; i < n; ++i ) {
            word = "";
            while ( j < m && str[j] != ' ' ) {
                word +=  str[j++];
            }
            j++;
            if ( p[pattern[i]] != w[word] ) {
                return false;
            }
            p[pattern[i]] = w[word] = i + 1;
        }
        return j == m + 1;
    }
};
