/* A string is said to be palindrome, if it reads the same from both the ends. Given a string S, you are allowed to perform cyclic shifts.
   More formally, you can pick any one character from any end (head or tail) and you can append that character at the other end. For example,
   if the string is "abc", then if we do a shift using the character at head position then the string becomes "bca". Similarly, if we do the shift
   using the character at the tail then the input string becomes "cab". Your task is to find out the minimum number of shifts needed to make the given string, a palindrome.
   In case, we can't convert the string to palindrome then print -1.

Input Format -> First line starts with T i.e. number of test cases, and then T lines will follow each containing a string "S".

Output Format -> Print the minimum number of cyclic shifts for each string if it can be made a palindrome, else -1.

Constraints:
1<=T<=100
1<=|S|<=300, S will contains only lower case alphabets ('a'-'z').

Sample Test Case :
Input:
4
abbb
aaabb
aabb
abc

Output:
-1
 1
 1
-1 */


#include<iostream>
using namespace std;

bool ispalindrome(string s)
{
  for(int i = 0, j = s.size()-1; i < j; i++, j--)
    if(s[i] != s[j])
      return false;
  return true;
}

void rotate_front(string& str)
{
  string s = str;
  for(int j = 0; j < str.size(); j++)
    s[j] = str[(j + 1) % str.size()];
  str = s;
}

void rotate_back(string& str)
{
  string s = str;
  s[0] = str[str.size() - 1];
  for(int j = str.size() - 1; j > 0; j--)
    s[j] = str[j - 1];
  str = s;
}

int main(){
  int T;
  cin >> T;
  while(T--)
  {
    int res = -1;
    string str, s1, s2;
    cin >> str;
    if(ispalindrome(str))
      cout << 0 << endl;
    else
    {
      s1 = s2 = str;
      for(int i = 0; i < str.size(); i++)
      {
        rotate_front(s1);
        rotate_back(s2);
        if(ispalindrome(s1) or ispalindrome(s2))
        {
          res = i + 1;
          break;
        }
      }
      cout << res << endl;
    }
  }
  return 0;
}
