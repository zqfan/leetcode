class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> p(n + 1);
        for ( int i = 0; i < n; ++i )
            p[i + 1] = p[i] + nums[i];
        deque<int> h;
        double result = -10000;
        for ( int i = k - 1; i < n; ++i ) {
            while ( h.size() > 1 && avg(p, h[h.size()-2], h.back()-1) >= avg(p, h.back(), i-k))
                h.pop_back();
            h.push_back(i - k + 1);
            while ( h.size() > 1 && avg(p, h[0], i) <= avg(p, h[1], i))
                h.pop_front();
            result = max(result, avg(p, h[0], i));
        }
        return result;
    }

    inline double avg(vector<double> & p, int i, int j) {
        return (p[j+1] - p[i]) / (j + 1 - i);
    }
};

// 74 / 74 test cases passed.
// Status: Accepted
// Runtime: 149 ms
// beats 52.19 %
