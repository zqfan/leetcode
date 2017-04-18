class Solution {
    long A [6][6] = {
        {0, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 1}
    };
    long m = 1000000007;
public:
    int checkRecord(int n) {
        matrixPow(A, n + 1);
        return A[5][2];
    }

    void matrixPow(long A [6][6], int n) {
        long tmp [6][6] = {0};
        for ( int i = 0; i < 6; ++i ) {
            tmp[i][i] = 1;
        }
        while ( n > 0 ) {
            if ( n & 1 == 1 ) {
                matrixMul(tmp, A);
            }
            matrixMul(A, A);
            n /= 2;
        }
        matrixCopy(A, tmp);
    }

    void matrixMul(long A [6][6], long B [6][6]) {
        long tmp [6][6] = {0};
        for ( int i = 0; i < 6; ++i ) {
            for ( int j = 0; j < 6; ++j ) {
                for ( int k = 0; k < 6; ++k ) {
                    tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % m;
                }
            }
        }
        matrixCopy(A, tmp);
    }

    void matrixCopy(long to [6][6], long from [6][6]) {
        for ( int i = 0; i < 6; ++i ) {
            for ( int j = 0; j < 6; ++j ) {
                to[i][j] = from[i][j];
            }
        }
    }
};

// 58 / 58 test cases passed.
// Status: Accepted
// Runtime: 6 ms
