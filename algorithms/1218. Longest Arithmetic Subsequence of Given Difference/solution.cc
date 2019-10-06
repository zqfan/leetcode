class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int result = 1;
        for (int n : arr) {
            if (m.count(n - difference) > 0) {
                m[n] = m[n - difference] + 1;
                result = max(result, m[n]);
            } else {
                m[n] = 1;
            }
        }
        return result;
    }
};
