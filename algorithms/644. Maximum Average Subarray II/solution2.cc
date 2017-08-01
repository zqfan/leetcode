class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double lo = -10000, hi = 10000, mid;
        while ( hi - lo >= 1e-5 ) {
            mid = (hi + lo) / 2;
            if ( possible(nums, k, mid) )
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }

    bool possible(vector<int> & nums, int k, double mid) {
        double sum = 0, ksum = 0, minsum = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            sum += nums[i] - mid;
            if ( i >= k ) {
                ksum += nums[i-k] - mid;
                minsum = min(minsum, ksum);
            }
            if ( i >= k - 1 && sum >= minsum )
                return true;
        }
        return false;
    }
};

// 74 / 74 test cases passed.
// Status: Accepted
// Runtime: 116 ms
// beats 77.78 %
