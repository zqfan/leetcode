class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, path, result);
        return result;
    }

    void dfs(int pos, vector<int> & C, int T, vector<int> & path, vector<vector<int>> & res) {
        if ( 0 == T ) {
            res.push_back(path);
            return;
        }
        for ( int i = pos; i < C.size(); ++i ) {
            if ( C[i] > T ) return;
            if ( i > pos && C[i] == C[i-1] ) continue;
            path.push_back(C[i]);
            dfs(i + 1, C, T - C[i], path, res);
            path.pop_back();
        }
    }
};
