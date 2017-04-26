class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs("", n, n, result);
        return result;
    }

    void dfs(string path, int left, int right, vector<string> & result) {
        if ( left >= 0 && right >= left ) {
            if ( right == 0 ) {
                result.push_back(path);
                return;
            }
            dfs(path + "(", left - 1, right, result);
            dfs(path + ")", left, right - 1, result);
        }
    }
};
