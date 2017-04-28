class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> r;
        for ( int i = 0; i < input.size(); ++i ) {
            char c = input[i];
            if ( ! isdigit(c) ) {
                for ( int x : diffWaysToCompute(input.substr(0, i)) ) {
                    for ( int y : diffWaysToCompute(input.substr(i + 1)) ) {
                        r.push_back(c == '+' ? x + y : c == '-' ? x - y : x * y);
                    }
                }
            }
        }
        return r.empty() ? vector<int> (1, stoi(input)) : r;
    }
};
