class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // based on @vaputa
        int m = nums1.size(), n = nums2.size();
        double median = findKth(nums1.begin(), m, nums2.begin(), n, (m + n + 1) / 2);
        if ( (m + n) % 2 == 0 )
            median = (median + findKth(nums1.begin(), m, nums2.begin(), n, (m + n + 2) / 2)) / 2;
        return median;
    }

    double findKth(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k) {
        if ( m > n )
            return findKth(B, n, A, m, k);
        if ( 0 == m )
            return *(B + k - 1);
        if ( 1 == k )
            return min(*A, *B);
        int i = min(m, k / 2), j = min(n, k / 2);
        if ( *(A + i - 1) > *(B + j - 1) )
            return findKth(A, m, B + j, n - j, k - j);
        else
            return findKth(A + i, m - i, B, n, k - i);
    }
};

// 2080 / 2080 test cases passed.
// Status: Accepted
// Runtime: 49 ms
// beats 78.02 %
