class Solution {
    map<int, bool> mem;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ( desiredTotal <= 0 ) {
            return true;
        }
        int limit = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if ( desiredTotal > limit ) {
            return false;
        }
        int fp = pow(2, maxChoosableInteger) - 1;
        return dfs(fp, desiredTotal);
    }

    bool dfs(int fp, int t) {
        if ( t <= 0 ) {
            return false;
        }
        if ( mem.find(fp) == mem.end() ) {
            mem.insert(make_pair(fp, false));
            int tmp = fp;
            for ( int i = 0; tmp > 0; i++, tmp >>= 1 ) {
                if ( (tmp & 1) == 0 ) {
                    continue;
                }
                if ( ! dfs(fp ^ (1 << i), t - i - 1) ) {
                    mem[fp] = true;
                    break;
                }
            }
        }
        return mem[fp];
    }
};
