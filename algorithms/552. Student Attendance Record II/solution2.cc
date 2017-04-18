class Solution {
public:
    int checkRecord(int n) {
        // based on @vinod23
        long m = 1000000007;
        long A0L0 = 1, A0L1 = 0, A0L2 = 0, A1L0 = 0, A1L1 = 0, A1L2 = 0, tmp;
        // iterate one more step to avoid complex expression when return
        for ( int i = 0; i <= n; ++i ) {
            // append P
            tmp = (A0L0 + A0L1 + A0L2) % m;
            // append L
            A0L2 = A0L1;
            // append L
            A0L1 = A0L0;
            A0L0 = tmp;
            // replace last P with A to A0L0, append P to others
            tmp = (A0L0 + A1L0 + A1L1 + A1L2) % m;
            // append L
            A1L2 = A1L1;
            // append L
            A1L1 = A1L0;
            A1L0 = tmp;
        }
        return int(A1L0);
    }
};
