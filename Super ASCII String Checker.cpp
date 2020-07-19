/* In the Byteland country, a string "S" is said to super ASCII string if and only if the count of each character in the string is equal to its ASCII value.
   In the Byteland country ASCII code of 'a' is 1, 'b' is 2 ...'z' is 26. Your task is to find out whether the given string is a super ASCII string or not.

Input Format -> First line contains number of test cases T, followed by T lines, each containing a string "S".

Output Format -> For each test case print "YES" if the String "S" is super ASCII, else print "NO"

Constraints:
1<=T<=100
1<=|S|<=400, S will contains only lower case alphabets ('a'-'z').

Sample Test case:
Input:
2
bba
scca

Output:
YES NO  */


#include <iostream>
using namespace std;
int main()
{
  string s;
  int i, numbers[100] = {0}, isAscii, n;
  cin >> n;
  while(n--)
  {
  	cin >> s;
  	i = 0;
  	isAscii = 1;
   		while(s[i] != '\0')
        {
        	if((s[i] >= 'a') && (s[i] <= 'z'))
            {
            	numbers[s[i] - 'a']++;
            }
  			s[i] = '\0';
			i++;
        }
		for(i = 0; i < 26; i++)
		{
			if((numbers[i] > 0) && (numbers[i] != (i + 1)))
            {
				isAscii = 0;
            }
		numbers[i] = 0;
		}
		if(isAscii)
        {
			cout << "YES ";
        }
		else
        {
			cout << "NO ";
        }
  }
  return 0;
}
