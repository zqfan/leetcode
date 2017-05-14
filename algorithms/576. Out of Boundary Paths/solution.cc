class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const int MOD = 1000000007;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int paths = 0;
        map<pair<int, int>, int> cur, next;
        cur[make_pair(i, j)] = 1;
        for ( int i = 0; i < N; ++i ) {
            next.clear();
            for ( auto & p : cur ) {
                int x = p.first.first, y = p.first.second, cnt = p.second;
                for ( int d = 0; d < 4; ++d ) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if ( 0 <= nx && nx < m && 0 <= ny && ny < n ) {
                        next[make_pair(nx, ny)] += cnt;
                        next[make_pair(nx, ny)] %= MOD;
                    } else {
                        paths += cnt;
                        paths %= MOD;
                    }
                }
            }
            cur = next;
        }
        return paths;
    }
};

// 94 / 94 test cases passed.
// Status: Accepted
// Runtime: 39 ms
// beats 8.26 % 
