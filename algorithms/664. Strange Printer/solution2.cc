class Solution {
    int f[101][101];
public:
    int strangePrinter(string s) {
        memset(f, 0, sizeof(f));
        return dfs(s, 0, s.size() - 1);
    }

    int dfs(string & s, int l, int r) {
        if ( l > r )
            return 0;
        if ( l == r )
            return 1;
        if ( 0 == f[l][r] ) {
            f[l][r] = dfs(s, l+1, r) + 1;
            for ( int i = l+1; i <= r; ++i )
                if ( s[l] == s[i] )
                    f[l][r] = min(f[l][r], dfs(s, l, i-1) + dfs(s, i+1, r));
        }
        return f[l][r];
    }
};

// 201 / 201 test cases passed.
// Status: Accepted
// Runtime: 29 ms
