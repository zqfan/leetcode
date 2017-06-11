class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> open(n + 1), closed(n + 1);
        for ( string & w : dict ) {
            int i = -1;
            while ( (i = s.find(w, i + 1)) != string::npos ) {
                ++open[i];
                ++closed[i + w.size()];
            }
        }
        string tagged;
        int pre = 0;
        for ( int i = 0, t = 0; i <= n; ++i ) {
            if ( open[i] && 0 == t && ! closed[i] ) {
                tagged += s.substr(pre, i - pre) + "<b>";
                pre = i;
            }
            t += open[i];
            t -= closed[i];
            if ( closed[i] && 0 == t && ! open[i] ) {
                tagged += s.substr(pre, i - pre) + "</b>";
                pre = i;
            }
        }
        return tagged + s.substr(pre);
    }
};

// 70 / 70 test cases passed.
// Status: Accepted
// Runtime: 23 ms
