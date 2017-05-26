class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m({" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        vector<string> res({""});
        for ( char d : digits ) {
            for ( int n = res.size(), i = 0; i < n; ++i ) {
                for ( char c : m[d - '0'] ) {
                    res.push_back(res[i] + c);
                }
                res[i] = res.back();
                res.pop_back();
            }
        }
        return digits.size() ? res : vector<string> ();
    }
};
