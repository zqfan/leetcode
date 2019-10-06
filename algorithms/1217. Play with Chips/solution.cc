class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int m[2] = {0,};
        for (int i : chips) {
            ++m[i & 1];
        }
        return min(m[0], m[1]);
    }
};
