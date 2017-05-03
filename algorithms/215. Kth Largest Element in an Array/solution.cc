class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size());
    }

    int findKthLargest(vector<int> & nums, int k, int start, int end) {
        if ( end - start < 2 ) {
            return nums[start];
        }
        int p = nums[start + rand() % (end - start)];
        int e = start, u = start, g = end;
        while ( u < g ) {
            if ( nums[u] > p ) {
                swap(nums[e], nums[u]);
                ++e;
                ++u;
            } else if ( nums[u] < p ) {
                --g;
                swap(nums[u], nums[g]);
            } else {
                ++u;
            }
        }
        if ( k <= e - start ) {
            return findKthLargest(nums, k, start, e);
        } else if ( k <= g - start ) {
            return nums[e];
        } else {
            return findKthLargest(nums, k - (g - start), g, end);
        }
    }
};
