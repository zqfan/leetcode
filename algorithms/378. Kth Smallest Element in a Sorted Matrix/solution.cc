class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flat;
        for ( int i = 0; i < matrix.size(); ++i ) {
            flat.insert(flat.end(), matrix[i].begin(), matrix[i].end());
        }
        sort(flat.begin(), flat.end());
        return flat[k-1];
    }
};

// 85 / 85 test cases passed.
// Status: Accepted
// Runtime: 53 ms
// beats 38.20 %
