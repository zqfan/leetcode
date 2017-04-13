class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs({{'(', ')'}, {'[', ']'}, {'{', '}'}});
        stack<char> left;
        for ( char c : s ) {
            if ( pairs.find(c) != pairs.end() ) {
                left.push(pairs[c]);
            } else if ( left.empty() || left.top() != c ) {
                return false;
            } else {
                left.pop();
            }
        }
        return left.empty();
    }
};
