class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        for ( int i = S.size() - 1; i >= 0; --i ) {
            if ( S[i] != '-' ) {
                if ( result.size() % (K + 1) == K ) {
                    result.push_back('-');
                }
                result.push_back(toupper(S[i]));
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
