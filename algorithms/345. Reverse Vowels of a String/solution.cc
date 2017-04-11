class Solution {
public:
    string reverseVowels(string s) {
        string letters = "aeiouAEIOU";
        unordered_set<char> vowels(letters.begin(), letters.end());
        int i = 0, j = s.size() - 1;
        while ( i < j ) {
            if ( vowels.find(s[i]) == vowels.end() ) {
                ++i;
            } else if (vowels.find(s[j]) == vowels.end() ) {
                --j;
            } else {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};
