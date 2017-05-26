class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counter(n + 1);
        for ( int c : citations ) {
            if ( c > n ) {
                ++counter[n];
            } else {
                ++counter[c];
            }
        }
        for ( int i = n; i > 0; --i ) {
            if ( counter[i] >= i ) {
                return i;
            }
            counter[i-1] += counter[i];
        }
        return 0;
    }
};
