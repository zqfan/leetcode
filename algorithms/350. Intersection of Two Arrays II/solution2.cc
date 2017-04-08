class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counter;
        for ( int n : nums1 ) {
            ++counter[n];
        }
        vector<int> result;
        for ( int n : nums2 ) {
            if ( --counter[n] >= 0 ) {
                result.push_back(n);
            }
        }
        return result;
    }
};

// 61 / 61 test cases passed.
// Status: Accepted
// Runtime: 6 ms
