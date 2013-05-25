/* Given an array of integers, find two numbers such that they add up
   to a specific target number.

   The function twoSum should return indices of the two numbers such
   that they add up to the target, where index1 must be less than
   index2. Please note that your returned answers (both index1 and
   index2) are not zero-based.

   You may assume that each input would have exactly one solution.

   Input: numbers={2, 7, 11, 15}, target=9
   Output: index1=1, index2=2
*/
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      vector<int> result;
      int i, j;
      for (i = 0; i < numbers.size(); i++) {
        for (j = i + 1; j < numbers.size(); j++) {
          if (numbers.at(i) + numbers.at(j) == target) {
            result.push_back(i+1);
            result.push_back(j+1);
          } // end if
        } // end for j
      } // end for i
      return result;
    }
};

int main() {
  Solution s;
  int a[] = {2, 7, 11, 15};
  vector<int> numbers;
  int i;
  for (i = 0; i < 4; i++)
    numbers.push_back(a[i]);
  vector<int> result = s.twoSum(numbers, 9);
  for (i = 0; i < 2; i++)
    cout << result.at(i);
  return 0;
}
