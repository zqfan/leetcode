class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string token;
        int maxlen = 0;
        map<int, int> pathlen({{0, 0}});
        while ( getline(ss, token) ) {
            auto pos = token.find_last_of('\t');
            string name = pos == string::npos ? token : token.substr(pos + 1);
            int depth = token.size() - name.size();
            if ( name.find('.') != string::npos ) {
                maxlen = max(maxlen, pathlen[depth] + int(name.size()));
            } else {
                pathlen[depth + 1] = pathlen[depth] + name.size() + 1;
            }
        }
        return maxlen;
    }
};
