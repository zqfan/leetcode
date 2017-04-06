class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        string keyboard [] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<unordered_set<char>> rows(3);
        for ( int i = 0; i < 3; i++ ) {
            rows[i] = unordered_set<char> (keyboard[i].begin(), keyboard[i].end());
        }
        for ( int i = 0; i < words.size(); i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                if ( rows[j].count(words[i][0]) != 0 ) {
                    result.push_back(words[i]);
                    for ( int k = 1; k < words[i].size(); k++ ) {
                        if ( rows[j].count(words[i][k]) == 0 ) {
                            result.pop_back();
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return result;
    }
};
