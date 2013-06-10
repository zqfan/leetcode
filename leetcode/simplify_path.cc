/* Copyright 2013 <ZhiQiang Fan>

   Given an absolute path for a file (Unix-style), simplify it.

   For example,
   path = "/home/", => "/home"
   path = "/a/./b/../../c/", => "/c"
*/
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
using std::string;
using std::vector;

class Solution {
  public:
  string simplifyPath(string path) {
    vector<string> dirs;
    string dir, result;
    std::size_t start = path.find('/'), end;

    if (start != 0)  // invalid input
      return "";
    while (start != string::npos) {
      end = path.find('/', start + 1);
      if (end != string::npos)
        dir = path.substr(start + 1, end - start - 1);
      else
        dir = path.substr(start + 1);

      if (dir == "..") {
        if (!dirs.empty())
          dirs.pop_back();
      } else if (dir != "." && dir != "") {
        dirs.push_back(dir);
      }

      if (end == path.size() - 1)
        break;
      start = end;
    }

    for (int i = 0; i < dirs.size(); i++)
      result += "/" + dirs[i];
    if (result == "")
      result = "/";
    return result;
  }
};

int main() {
  Solution s;
  assert(s.simplifyPath("") == "");
  assert(s.simplifyPath("/home/") == "/home");
  assert(s.simplifyPath("/a/./b/../../c/") == "/c");
  assert(s.simplifyPath("a/b/c") == "");
  assert(s.simplifyPath("/../") == "/");
  assert(s.simplifyPath("/a/../../../c") == "/c");
  assert(s.simplifyPath("/.") == "/");
  return 0;
}
