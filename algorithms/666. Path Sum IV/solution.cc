class Solution {
public:
    int pathSum(vector<int>& nums) {
        int s[5][8] = {0};
        for ( int n : nums ) {
            int r = n / 100;
            int c = n / 10 % 10 - 1;
            int v = n % 10;
            s[r][c] = s[r-1][c/2] + v;
        }
        int sum = 0;
        for ( int i = 1; i < 5; ++i )
            for ( int j = 0; j < 8; ++j )
                if ( i == 4 || s[i][j] && ! s[i+1][j*2] && ! s[i+1][j*2+1] )
                    sum += s[i][j];
        return sum;
    }
};

// 195 / 195 test cases passed.
// Status: Accepted
// Runtime: 3 ms
