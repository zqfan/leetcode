class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(1, n, k, path, result);
        return result;
    }

    void dfs(int i, int n, int k, vector<int> & path, vector<vector<int>> & result) {
        if ( path.size() == k && n == 0) {
            result.push_back(path);
        } else if ( path.size() < k ) {
            for ( int limit = min(n, 9); i <= limit; ++i ) {
                path.push_back(i);
                dfs(i + 1, n - i, k, path, result);
                path.pop_back();
            }
        }
    }
};
