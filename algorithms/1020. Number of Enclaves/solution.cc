class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (0 <= i && i < g.size() && 0 <= j && j < g[i].size() && g[i][j]) {
            g[i][j] = 0;
            dfs(g, i-1, j);
            dfs(g, i, j+1);
            dfs(g, i+1, j);
            dfs(g, i, j-1);
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        vector<vector<int>> g = A;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[0].size(); ++j) {
                if (i == 0 || j == 0 || i == g.size() - 1 || j == g[0].size() - 1)
                    dfs(g, i, j);
            }
        }
        int result = 0;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[0].size(); ++j) {
                result += g[i][j];
            }
        }
        return result;
    }
};
