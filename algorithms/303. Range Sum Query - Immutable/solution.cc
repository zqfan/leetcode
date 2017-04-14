class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        sums.push_back(0);
        for ( int n : nums ) {
            sums.push_back(sums.back() + n);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
