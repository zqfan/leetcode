/* Copyright 2013 <ZhiQiang Fan>

   Given two words word1 and word2, find the minimum number of steps
   required to convert word1 to word2. (each operation is counted as 1
   step.)

   You have the following 3 operations permitted on a word:

   a) Insert a character
   b) Delete a character
   c) Replace a character
*/
#include <cstdio>
#include <string>
using std::string;

class Solution {
public:
  int minDistance(string word1, string word2) {
    // a problem of longest common sub sequence
    if (word1.size() > word2.size())
      return this->minDistance(word2, word1);

    // get the length of longest common sub sequence

    return word2.size() - max_len;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.minDistance("", ""));
  printf("%d\n", s.minDistance("sea", "eat"));
  return 0;
}
