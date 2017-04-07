class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter [26] = { 0 };
        for ( char c : magazine ) {
            counter[c - 'a']++;
        }
        for ( char c : ransomNote ) {
            if ( counter[c - 'a']-- <= 0 ) {
                return false;
            }
        }
        return true;
    }
};
