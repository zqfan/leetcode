class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> group;
        for ( string & s : paths ) {
            istringstream iss(s);
            vector<string> tokens(istream_iterator<string> {iss}, istream_iterator<string> {});
            for ( int i = 1; i < tokens.size(); ++i ) {
                int p = tokens[i].find('(');
                string filename = tokens[i].substr(0, p);
                string content = tokens[i].substr(p + 1, tokens[i].size() - p - 2);
                group[content].push_back(tokens[0] + "/" + filename);
            }
        }
        vector<vector<string>> result;
        for ( auto & p : group ) {
            if ( p.second.size() > 1 ) {
                result.push_back(p.second);
            }
        }
        return result;
    }
};
