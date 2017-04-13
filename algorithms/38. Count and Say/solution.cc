class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        string cur;
        for ( int i = 1; i < n; ++i ) {
            cur = "";
            for ( int j = 1, count = 1; j <= result.size(); ++j ) {
                if ( j == result.size() || result[j] != result[j-1] ) {
                    cur += to_string(count);
                    cur.push_back(result[j-1]);
                    count = 1;
                } else {
                    ++count;
                }
            }
            result = cur;
        }
        return result;
    }
};
