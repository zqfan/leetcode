class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        set<int> v;
        q.push(make_pair(n, 1));
        while ( true ) {
            auto & p = q.front();
            int sq = sqrt(p.first);
            if ( sq * sq == p.first ) {
                return p.second;
            }
            for ( int i = sq; i > 0 ; --i ) {
                int j = p.first - i * i;
                if ( v.find(j) != v.end() ) {
                    continue;
                }
                q.push(make_pair(j, p.second + 1));
                v.insert(j);
            }
            q.pop();
        }
        return 0;
    }
};
