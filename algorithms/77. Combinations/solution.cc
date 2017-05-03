class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        bt(1, path, n, k, result);
        return result;
    }

    void bt(int start, vector<int> & path, int n, int k, vector<vector<int>> & result) {
        if ( path.size() == k ) {
            result.push_back(path);
            return;
        }
        for ( int i = start; i <= n; ++i ) {
            path.push_back(i);
            bt(i + 1, path, n, k, result);
            path.pop_back();
        }
    }
};
