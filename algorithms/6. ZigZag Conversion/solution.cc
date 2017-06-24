class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows < 2 || numRows >= s.size() )
            return s;
        vector<string> matrix(numRows);
        int row = 0, direction = 1;
        for ( char c : s ) {
            matrix[row].push_back(c);
            row += direction;
            if ( 0 == row || numRows - 1 == row )
                direction *= -1;
        }
        string result;
        for ( string & r : matrix )
            result += r;
        return result;
    }
};

// 1158 / 1158 test cases passed.
// Status: Accepted
// Runtime: 25 ms
// beats 72.41 %
