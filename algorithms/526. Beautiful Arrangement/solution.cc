class Solution {
public:
    int countArrangement(int N) {
        vector<int> arr(N);
        for ( int i = 0; i < N; ++i ) {
            arr[i] = i + 1;
        }
        return countArrangement(N, arr);
    }

    int countArrangement(int n, vector<int> & arr) {
        if ( n <= 0 ) {
            return 1;
        }
        int count = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( arr[i] % n == 0 || n % arr[i] == 0 ) {
                swap(arr[i], arr[n-1]);
                count += countArrangement(n - 1, arr);
                swap(arr[n-1], arr[i]);
            }
        }
        return count;
    }
};

// 15 / 15 test cases passed.
// Status: Accepted
// Runtime: 9 ms
// beats 77.61%
