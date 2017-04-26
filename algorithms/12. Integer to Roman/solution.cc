class Solution {
public:
    string intToRoman(int num) {
        vector<int> romans = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> letters = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string result;
        for ( int i = 0; i < romans.size(); ++i ) {
            while ( num >= romans[i] ) {
                result += letters[i];
                num -= romans[i];
            }
        }
        return result;
    }
};
