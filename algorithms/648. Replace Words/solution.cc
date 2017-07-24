class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        struct sTrie {
            sTrie * next[26] = {};
            string word;
            ~sTrie() {
                for ( int i = 0; i < 26; ++i )
                    if ( next[i] )
                        delete next[i];
            }
        };
        sTrie * t = new sTrie();
        for ( string & w : dict ) {
            sTrie * cur = t;
            for ( char c : w ) {
                if ( nullptr == cur->next[c - 'a'] )
                    cur->next[c - 'a'] = new sTrie();
                cur = cur->next[c - 'a'];
            }
            cur->word = w;
        }
        string result, word;
        istringstream iss(sentence);
        while ( iss >> word ) {
            sTrie * cur = t;
            for ( char c : word ) {
                if ( cur->word.size() > 0 ) {
                    word = cur->word;
                    break;
                }
                if ( nullptr == cur->next[c - 'a'] )
                    break;
                cur = cur->next[c - 'a'];
            }
            result += word + ' ';
        }
        delete t;
        result.pop_back();
        return result;
    }
};

// 124 / 124 test cases passed.
// Status: Accepted
// Runtime: 65 ms
