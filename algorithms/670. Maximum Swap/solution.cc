class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for ( int i = 0; i < s.size(); ++i )
            for ( int j = i + 1; j < s.size(); ++j ) {
                swap(s[i], s[j]);
                num = max(num, stoi(s));
                swap(s[i], s[j]);
            }
        return num;
    }
};

// 111 / 111 test cases passed.
// Status: Accepted
// Runtime: 3 ms
