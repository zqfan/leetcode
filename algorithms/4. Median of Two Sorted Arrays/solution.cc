class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), lo = 0, hi = m;
        if ( m > n )
            return findMedianSortedArrays(nums2, nums1);
        while ( lo <= hi ) {
            int i = (lo + hi) / 2;
            int j = (m + n + 1) / 2 - i;
            if ( i < m && nums1[i] < nums2[j - 1] )
                lo = i + 1;
            else if ( i > 0 && nums1[i - 1] > nums2[j] )
                hi = i - 1;
            else {
                int max_of_left = max(i > 0 ? nums1[i - 1] : INT_MIN,
                                      j > 0 ? nums2[j - 1] : INT_MIN);
                if ( (m + n) % 2 == 1 )
                    return max_of_left;
                int min_of_right = min(i < m ? nums1[i] : INT_MAX,
                                       j < n ? nums2[j] : INT_MAX);
                return (max_of_left + min_of_right) / 2.0;
            }
        }
    }
};

// 2080 / 2080 test cases passed.
// Status: Accepted
// Runtime: 52 ms
// beats 71.71 %
