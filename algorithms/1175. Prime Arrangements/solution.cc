class Solution {
public:
    int numPrimeArrangements(int n) {
        long m = 1000000007, primeCnt = 0, ans = 1;
        for (int i = 2; i <= n; ++i) {
            ++primeCnt;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    --primeCnt;
                    break;
                }
            }
        }
        for (int i = 2; i <= primeCnt; ++i) {
            ans = (ans * i) % m;
        }
        for (int i = 2; i <= (n - primeCnt); ++i) {
            ans = (ans * i) % m;
        }
        return (int)ans;
    }
};
