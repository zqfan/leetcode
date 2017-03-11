/* Copyright 2013 <ZhiQiang Fan>

    Given a string, determine if it is a palindrome, considering only
    alphanumeric characters and ignoring cases.
    For example,
    "A man, a plan, a canal: Panama" is a palindrome.
    "race a car" is not a palindrome.
    Note:
    Have you consider that the string might be empty? This is a good
    question to ask during an interview.
    For the purpose of this problem, we define empty string as valid
    palindrome.
*/
#include <cstdio>
#include <string>
using std::string;

class Solution {
  public:
  bool isPalindrome(string s) {
    int i, j;

    i = 0;
    j = s.size() - 1;
    while (i <= j) {
      while (i <= j && !std::isalnum(s[i]))
        i++;
      while (i <= j && !std::isalnum(s[j]))
        j--;
      if (i <= j && std::tolower(s[i]) != std::tolower(s[j]))
        return false;
      i++;
      j--;
    }

    return true;
  }
};

int main() {
  printf("%d\n", Solution().isPalindrome("1a2"));
  return 0;
}
