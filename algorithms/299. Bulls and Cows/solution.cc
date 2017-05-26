class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int count[10] = {0};
        for ( int i = 0; i < secret.size(); ++i ) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if ( s == g ) {
                ++A;
                continue;
            }
            if ( count[s] < 0 ) ++B;
            if ( count[g] > 0 ) ++B;
            ++count[s];
            --count[g];
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
