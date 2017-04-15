class Solution {
public:
    int reverse(int x) {
        try {
            string s = to_string(abs(x));
            std::reverse(s.begin(), s.end());
            return x > 0 ? stoi(s) : -stoi(s);
        } catch ( exception ) {
            return 0;
        }
    }
};
