class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        char pre = ' ';
        for ( char c : s ) {
            if ( isspace(c) && !isspace(pre) ) {
                ++count;
            }
            pre = c;
        }
        return count + int(!isspace(pre));
    }
};
