class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // since we can rearrange the string, to check s[i:j] can be palindrome,
        // we only need to count the odd char, use count[N][26] as prefix sum,
        // we can do count[j][0:26] - count[i][0:26] to get the odd count.
        // notice that 26 can be cover by int, and count odd number can use XOR.
        vector<int> oddPrefixSum(s.size()+1);
        for (int i = 0; i < s.size(); ++i) {
            oddPrefixSum[i+1] = oddPrefixSum[i] ^ (1 << (s[i] - 'a'));
        }
        vector<bool> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int odd = oddPrefixSum[queries[i][1]+1] ^ oddPrefixSum[queries[i][0]];
            int bitCnt = 0;
            while (odd > 0) {
                bitCnt += odd & 1;
                odd >>= 1;
            }
            answer[i] = bitCnt / 2 <= queries[i][2];
        }
        return answer;
    }
};
