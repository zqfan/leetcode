class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0, p2 = 0, tmp;
        for ( int n : nums ) {
            tmp = p2;
            p2 = max(p1 + n, p2);
            p1 = tmp;
        }
        return p2;
    }
};
