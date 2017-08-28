class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while ( lo < hi ) {
            int mid = lo + (hi - lo) / 2, cnt = 0;
            for ( int i = 1; i <= m; ++i )
                cnt += min(mid / i, n);
            if ( cnt >= k )
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

// 69 / 69 test cases passed.
// Status: Accepted
// Runtime: 26 ms
