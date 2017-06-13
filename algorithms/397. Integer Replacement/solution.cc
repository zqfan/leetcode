class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        unsigned int m = n; // for 2147483647
        while ( m > 1 ) {
            if ( m % 2 == 0 )
                m /= 2;
            else if ( m % 4 == 1 || 3 == m )
                --m;
            else
                ++m;
            ++count;
        }
        return count;
    }
};
