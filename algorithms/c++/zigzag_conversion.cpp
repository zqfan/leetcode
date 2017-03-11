/* The string "PAYPALISHIRING" is written in a zigzag pattern on a
   given number of rows like this: (you may want to display this
   pattern in a fixed font for better legibility)

   P   A   H   N
   A P L S I I G
   Y   I   R

   P Y A I H R N
   A P L S I I G

   P   I   N
   A L S I G
   Y A H R
   P   I

   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion
   given a number of rows:
   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". */
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
      string result, tmp;
      vector<char> matrix;
      int i = 0, j;
      bool odd = true;
      while (true) {
        if (odd) {
          tmp = s.substr(i, nRows);
          for (j = 0; j < tmp.size(); j++)
            matrix.push_back(tmp.at(j));
          // fill the last col with null to align
          while (matrix.size() % nRows != 0)
            matrix.push_back(' ');
          i += nRows;
          odd = false;
        }
        else { // even col
          if (nRows > 2) {
            tmp = s.substr(i, nRows - 2);
            matrix.push_back(' ');
            // fill the last col with null to align
            for(j = 0; j < nRows - 2 - tmp.size(); j++)
              matrix.push_back(' ');
            for (j = tmp.size() - 1; j >= 0; j--)
              matrix.push_back(tmp.at(j));
            matrix.push_back(' ');
            i += nRows - 2;
          }
          odd = true;
        }
        if (i >= s.size())
          break;
      } // end while true
      for (i = 0; i < nRows; i++) {
        for (j = 0; j + i < matrix.size(); j += nRows) {
          if (matrix.at(j + i) != ' ')
            result += matrix.at(j + i);
        }
      }
      return result;
    }
};

int main() {
  Solution sol;
  string s = "ABCDEFGH";
  cout << sol.convert(s, 4) << endl;
  return 0;
}
