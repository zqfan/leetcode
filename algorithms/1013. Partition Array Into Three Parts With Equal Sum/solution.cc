class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0), counter = 0;
        if (sum % 3 != 0)
            return false;
        for (int i = 0, cur = 0; i < A.size() && counter < 3; ++i) {
            cur += A[i];
            if (cur == sum / 3) {
                ++counter;
                cur = 0;
            }
        }
        return counter >= 3;
    }
};
