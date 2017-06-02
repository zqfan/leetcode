class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(0, s, path, result);
        return result;
    }

    void dfs(int p, string & s, vector<string> & path, vector<vector<string>> & result) {
        if ( s.size() == p ) {
            result.push_back(path);
            return;
        }
        for ( int i = p; i < s.size(); ++i ) {
            int l = p, r = i;
            while ( l < r && s[l] == s[r] ) {
                ++l;
                --r;
            }
            if ( l >= r ) {
                path.push_back(s.substr(p, i - p + 1));
                dfs(i + 1, s, path, result);
                path.pop_back();
            }
        }
    }
};
