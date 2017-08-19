class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto r = upper_bound(arr.begin(), arr.end(), x), l = r - 1;
        while ( k-- )
            (l >= arr.begin() && (r >= arr.end() || x - *l <= *r - x)) ? --l : ++r;
        return vector<int> (++l, r);
    }
};

// 55 / 55 test cases passed.
// Status: Accepted
// Runtime: 115 ms
// beats 91.55 %
