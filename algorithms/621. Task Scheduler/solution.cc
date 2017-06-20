class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(256);
        for ( char t : tasks )
            ++counter[t];
        int m = *max_element(counter.begin(), counter.end());
        int l = count(counter.begin(), counter.end(), m);
        return max(int(tasks.size()), (m - 1) * (n + 1) + l);
    }
};

// 64 / 64 test cases passed.
// Status: Accepted
// Runtime: 63 ms
