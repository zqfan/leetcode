class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> bold(s.size() + 2);
        vector<string> sdict(dict);
        auto cmp = [] (string & a, string & b) { return a.size() > b.size(); };
        sort(sdict.begin(), sdict.end(), cmp);
        for ( int i = 0, j; i < s.size(); ++i ) {
            for ( j = 0; j < sdict.size(); ++j )
                if ( s.find(sdict[j], i) == i )
                    break;
            if ( j < sdict.size() )
                fill(bold.begin() + i + 1, bold.begin() + i + 1 + sdict[j].size(), true);
        }
        string t;
        for ( int i = 1; i <= s.size(); ++i ) {
            if ( ! bold[i-1] && bold[i] ) t += "<b>";
            t += s[i-1];
            if ( bold[i] && ! bold[i+1] ) t += "</b>";
        }
        return t;
    }
};

// 70 / 70 test cases passed.
// Status: Accepted
// Runtime: 292 ms
