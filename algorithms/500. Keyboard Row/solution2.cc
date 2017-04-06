class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        string keyboard [] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<set<char>> rows(3);
        for ( int i = 0; i < 3; i++ ) {
            rows[i] = set<char> (keyboard[i].begin(), keyboard[i].end());
        }
        for ( int i = 0; i < words.size(); i++ ) {
            set<char> word(words[i].begin(), words[i].end());
            set<char> intersect;
            for ( int j = 0; j < 3; j++ ) {
                set_intersection(rows[j].begin(), rows[j].end(),
                                 word.begin(), word.end(),
                                 inserter(intersect, intersect.begin()));
                if ( intersect.size() == word.size() ) {
                    result.push_back(words[i]);
                    break;
                }
                if ( intersect.size() > 0 ) {
                    break;
                }
            }
        }
        return result;
    }
};
