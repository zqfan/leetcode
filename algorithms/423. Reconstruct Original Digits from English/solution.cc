class Solution {
public:
    string originalDigits(string s) {
        vector<int> nums(10);
        vector<int> indices = { 0, 2, 4, 1, 3, 5, 6, 7, 8, 9 };
        vector<char> unique = { 'z', 'w', 'u', 'o', 'r', 'f', 'x', 's', 'g', 'i' };
        vector<string> words = { "zero", "two", "four", "one", "three", "five", "six", "seven", "eight", "nine" };
        unordered_map<char, int> counter;
        for ( char c : s ) {
            ++counter[c];
        }
        for ( int i = 0; i < 10; ++i ) {
            nums[indices[i]] = counter[unique[i]];
            int n = counter[unique[i]];
            for ( char c : words[i] ) {
                counter[c] -= n;
            }
        }
        string result;
        for ( int i = 0; i < 10; ++i ) {
            result += string(nums[i], i + '0');
        }
        return result;
    }
};
