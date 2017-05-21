class Solution {
public:
    string fractionAddition(string expression) {
        expression += "+";
        int rn = 0, rd = 1, f = 1, n = 0, d = 0, isN = 1;
        for ( int i = 0, sz = expression.size(); i < sz; ++i ) {
            if ( '+' == expression[i] || '-' == expression[i] ) {
                if ( i == 0 ) {
                    f = -1;
                    continue;
                }
                int g = gcd(rd, d);
                rn = rn * d / g + f * n * rd / g;
                rd *= d / g;
                n = d = 0;
                isN = 1;
                f = expression[i] == '+' ? 1 : -1;
            } else if ( '/' == expression[i] ) {
                isN = 0;
            } else if ( isN ) {
                n = n * 10 + expression[i] - '0';
            } else {
                d = d * 10 + expression[i] - '0';
            }
        }
        int g = gcd(abs(rn), rd);
        return to_string(rn / g) + "/" + to_string(rd / g);
    }

    int gcd(int a, int b) {
        while ( b ) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};
