class Solution {
public:
    int getSum(int a, int b) {
        int sum;
        while ( b ) {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }
};
