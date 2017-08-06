class Solution {
public:
    int maxA(int N) {
        if ( N < 7 )
            return N;
        if ( 10 == N )
            return 20;
        int n = N / 5 + 1;
        int n3 = n * 5 - 1 - N;
        return pow(3, n3) * pow(4, n - n3);
    }
};
