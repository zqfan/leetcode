class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, INT_MAX);
        ugly[0] = 1;
        vector<vector<int>> heap;
        int m = primes.size();
        for ( int i = 0; i < m; ++i ) {
            heap.push_back({-primes[i], 0, primes[i]});
        }
        make_heap(heap.begin(), heap.end());
        for ( int i = 1; i < n; ++i ) {
            ugly[i] = -heap[0][0];
            while ( -heap[0][0] == ugly[i] ) {
                pop_heap(heap.begin(), heap.end());
                ++heap[m-1][1];
                heap[m-1][0] = -ugly[heap[m-1][1]] * heap[m-1][2];
                push_heap(heap.begin(), heap.end());
            }
        }
        return ugly[n-1];
    }
};

// 83 / 83 test cases passed.
// Status: Accepted
// Runtime: 109 ms
// beats 12.64 %
