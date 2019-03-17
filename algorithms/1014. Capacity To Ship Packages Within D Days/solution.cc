class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for (int w : weights) {
            left = max(w, left);
            right += w;
        }
        while (left <= right) {
            int mid = (left + right) / 2, bucket = 1, cur = 0;
            for (int w : weights) {
                if (w + cur > mid) {
                    cur = 0;
                    bucket++;
                }
                cur += w;
            }
            if (bucket <= D) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
