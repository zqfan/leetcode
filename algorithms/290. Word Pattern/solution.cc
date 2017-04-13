class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p;
        unordered_map<string, int> w;
        int n = pattern.size(), i = 0;
        stringstream ss(str);
        string word;
        while ( ss >> word ) {
            if ( i == n || p[pattern[i]] != w[word] ) {
                return false;
            }
            p[pattern[i]] = w[word] = i + 1;
            ++i;
        }
        return i == n;
    }
};
