class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // based on Kadane's algorithm.
        // for arr[i], maxSum means dp result for arr[0:i-1] ends at i-1 without deletion.
        // maxSumExclude means dp result for arr[0:i-1] ends at i-1 with one deletion.
        // we need to return max value instead of 0 for all negative numbers case.
        int answer = 0, maxSum = 0, maxSumExclude = 0, maximum = arr[0];
        for (int n : arr) {
            maximum = max(maximum, n);
            // it might be excluded, so use maxSum,
            // or included, so use last maxSumExclude + n
            maxSumExclude = max(maxSumExclude + n, maxSum);
            maxSum += n;
            answer = max(answer, max(maxSum, maxSumExclude));
            maxSum = max(maxSum, 0);
            maxSumExclude = max(maxSumExclude, 0);
        }
        return maximum < 0 ? maximum : answer;
    }
};
