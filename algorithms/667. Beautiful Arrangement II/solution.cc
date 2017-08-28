class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l = 1, r = k + 1;
        while ( l < r ) {
            res.push_back(l++);
            res.push_back(r--);
        }
        if ( l == r )
            res.push_back(l);
        for ( int i = k + 2; i <= n; ++i )
            res.push_back(i);
        return res;
    }
};

// 68 / 68 test cases passed.
// Status: Accepted
// Runtime: 36 ms
