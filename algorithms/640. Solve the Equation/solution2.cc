class Solution {
public:
    string solveEquation(string equation) {
        // @kennethsnnow
        int p = equation.find('=');
        pair<double, double> l = parse(equation.substr(0, p));
        pair<double, double> r = parse(equation.substr(p+1));
        double x = l.first - r.first, val = r.second - l.second;
        return x ? "x=" + to_string(int(val / x)) : val ? "No solution" : "Infinite solutions";
    }

    pair<double, double> parse(string s) {
        double x = 0, val = 0;
        for ( int i = 0; i < s.size(); ++i ) {
            int num = getNum(s, i);
            if ( 'x' == s[i] ) {
                x += num;
            } else {
                val += num;
                --i;
            }
        }
        return {x, val};
    }

    int getNum(string & s, int & pos) {
        int num = 0, cnt = 0, init = pos;
        if ( '-' == s[pos] || '+' == s[pos] )
            ++pos;
        while ( pos < s.size() && '0' <= s[pos] && s[pos] <= '9' ) {
            num = num * 10 + s[pos] - '0';
            ++cnt;
            ++pos;
        }
        if ( 0 == cnt )
            num = 1;
        return '-' == s[init] ? -num : num;
    }
};

// 52 / 52 test cases passed.
// Status: Accepted
// Runtime: 0 ms
