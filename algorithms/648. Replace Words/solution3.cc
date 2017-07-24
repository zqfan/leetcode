class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> d(dict.begin(), dict.end());
        string result, word, wordsub;
        istringstream iss(sentence);
        while ( iss >> word ) {
            for ( int i = 1; i <= word.size(); ++i ) {
                wordsub = word.substr(0, i);
                if ( d.find(wordsub) != d.end() ) {
                    word = wordsub;
                    break;
                }
            }
            result += word + ' ';
        }
        result.pop_back();
        return result;
    }
};

// 124 / 124 test cases passed.
// Status: Accepted
// Runtime: 189 ms
