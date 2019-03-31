class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result(A.size());
        for (int i = 0, m = 0; i < A.size(); ++i) {
            m = ((m << 1) + A[i]) % 5;
            result[i] = !m;
        }
        return result;
    }
};
