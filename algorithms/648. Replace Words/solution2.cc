class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        // inspired by @ SlavaSSU
        unordered_map<double, string> m;
        for ( auto & w : dict ) {
            double cur = 1, base = 26, hash = 0;
            for ( char c : w ) {
                hash = hash + (c - 'a' + 1) * cur;
                cur *= base;
            }
            m[hash] = w;
        }
        string result, word;
        istringstream iss(sentence);
        while ( iss >> word ) {
            double cur = 1, base = 26, hash = 0;
            for ( int i = 0; i < word.size(); ++i ) {
                hash = hash + (word[i] - 'a' + 1) * cur;
                cur *= base;
                if ( m.count(hash) ) {
                    word = word.substr(0, i + 1);
                    break;
                }
            }
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};

// 124 / 124 test cases passed.
// Status: Accepted
// Runtime: 72 ms
