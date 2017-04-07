class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counter;
        for ( char c : magazine ) {
            if ( counter.find(c) == counter.end() ) {
                counter[c] = 1;
            } else {
                counter[c]++;
            }
        }
        for ( char c : ransomNote ) {
            if ( counter.find(c) == counter.end() or counter[c] == 0 ) {
                return false;
            }
            counter[c]--;
        }
        return true;
    }
};
