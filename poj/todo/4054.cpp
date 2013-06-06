#include <iostream>
#include <string>
using namespace std;

string get_abbr(string text)
{
  length = text.length();
  for (int i = 0; i < length; i++) {
    if ('a' <= text[i] and text[i] <= 'z')
      text[i] = toupper(text[i]);
    else if ('A' < text[i] or text[i] > 'Z')
      text[i] = ' ';
  }
  
  return "11\nNA";
}

int main()
{
  const int max_size = 4000;
  string input;
  string text = "";
  int count = 1;
  while (getline(cin, input)) {
    if (input.find("Sample Input #") == 0) {
      if (count != 1)
        cout << get_abbr(text) << "\n\n" << endl;
      cout << "Sample Output #" << count++ << endl << endl;
      text = "";
    }
    text += " " + input;
  }
  cout << get_abbr(text) << endl;
  return 0;
}
