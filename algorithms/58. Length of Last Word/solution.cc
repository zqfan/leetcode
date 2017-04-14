class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i = s.size();
        while ( --i >= 0 && s[i] == ' ') ;
        while ( i >= 0 && s[i--] != ' ') {
            ++len;
        }
        return len;
    }
};
