class Solution {
public:
    int bulbSwitch(int n) {
        int on = 0;
        for ( int i = 1; i * i <= n; ++i ) {
            ++on;
        }
        return on;
    }
};
