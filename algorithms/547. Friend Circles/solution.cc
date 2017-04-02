class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visited(M.size());
        int circle = 0;
        for ( int i = 0; i < M.size(); i++ ) {
            if ( 0 == visited[i] ) {
                dfs(i, M, visited);
                circle++;
            }
        }
        return circle;
    }

    void dfs(int i, vector<vector<int>> & M, vector<int> & visited) {
        visited[i] = 1;
        for ( int j = 0; j < M[i].size(); j++ ) {
            if ( 1 == M[i][j] && 0 == visited[j] ) {
                dfs(j, M, visited);
            }
        }
    }
};
