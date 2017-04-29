class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for ( string & w : d ) {
            if ( issubseq(w, s) ) {
                if ( w.size() > result.size() ) {
                    result = w;
                } else if ( w.size() == result.size() ) {
                    result = min(result, w);
                }
            }
        }
        return result;
    }

    bool issubseq(string & x, string & y) {
        int i = 0;
        for ( int j = 0; i < x.size() && j < y.size(); ++j ) {
            if ( y[j] == x[i] ) {
                ++i;
            }
        }
        return i == x.size();
    }
};
