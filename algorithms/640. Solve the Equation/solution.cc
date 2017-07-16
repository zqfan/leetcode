class Solution {
public:
    string solveEquation(string equation) {
        // @mzchen
        // normalize the equation, add 1 for x's which have no coefficient: x => 1x
        // note that +-= has different effect
        string e = regex_replace(equation, regex("(^|[=+-])x"), "$011x");
        cout << e << endl;
        int p = e.find('=');
        pair<double, double> l = parse(e.substr(0, p));
        pair<double, double> r = parse(e.substr(p+1));
        double x = l.first - r.first, val = r.second - l.second;
        return x ? "x=" + to_string(int(val / x)) : val ? "No solution" : "Infinite solutions";
    }

    pair<double, double> parse(string s) {
        auto e = regex("(^|[+-])\\d+x?");
        regex_token_iterator<string::iterator> it(s.begin(), s.end(), e), end;
        double x = 0, val = 0;
        for ( ; it != end; ++it )
            (it->str().back() == 'x' ? x : val) += stoi(*it);
        return {x, val};
    }
};

// 52 / 52 test cases passed.
// Status: Accepted
// Runtime: 23 ms
