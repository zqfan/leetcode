/*
Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack,
or null if needle is not part of haystack.
*/
#include <cstdio>

class Solution {
public:
  // using kmp
  char *strStr(char *haystack, char *needle) {
    if (!needle[0]) return haystack;
    // get length of needle
    int i = -1;
    while (needle[++i]) {}
    int next[i];  // C99 style
    _gen_next_arr(needle, next);
    int j = 0;
    i = 0;
    while (haystack[i]) {
      if (haystack[i] == needle[j]) {
        i++, j++;
      } else if (next[j] != -1) {
        j = next[j];
      } else {  // needle[j] == needle[0] and haystack[i] != needle[0]
        j = 0;
        i++;
      }
      if (!needle[j])
        return haystack+i-j;
    }
    return NULL;
  }

  // kmp next array generator, actually the comments are unnecessary..
  void _gen_next_arr(const char * p, int * next) {
    int i = 0;  // index of p
    int k = -1;  // magic number
    next[i] = k;
    while (p[i]) {
      if (k == -1 || p[k] == p[i]) {
        i++, k++;
        if (p[k] == p[i])
          next[i] = next[k];  // same recursive position
        else
          next[i] = k;  // not match, recursive to k position
      } else {
        k = next[k];  // search previous position
      }
    }
  }
};

int main() {
  Solution s;
  char h[32] = "mississippi";
  char n[32] = "issip";
  char * r = s.strStr(h, n);
  if (r)
    printf("%s\n", r);
  return 0;
}
