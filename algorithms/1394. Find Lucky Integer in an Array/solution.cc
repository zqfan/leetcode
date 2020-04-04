class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::unordered_map<int, int> m;
        for (int n : arr)
            m[n]++;
        int result = -1;
        for (auto it : m)
            result = it.first == it.second ? max(result, it.first) : result;
        return result;
    }
};

// Runtime: 12 ms, faster than 78.22% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.4 MB, less than 100.00% of C++ online submissions for Find Lucky Integer in an Array.
