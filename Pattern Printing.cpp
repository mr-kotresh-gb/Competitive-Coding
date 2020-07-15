/* Decode the logic and print the pattern that corresponds to the given input.

Input Format -> Single Integer N.

Output Format -> Output is the form of pattern.

Constraints -> (2 <= N <= 100)

Sample Input -> 3

Sample Output ->
10203010011012
  **4050809
  ****607  */
  
#include<iostream>
using namespace std;

int main()
{
  int n, star = 0, space;
  int i, j, l, r;
  cin >> n;
  l = 1;
  r = n * n + 1;
  for(i = n; i > 0; i--)
  {
    for(space = 1; space <= star; space++)
      cout << "*";
    star += 2;
    for(j = 1; j <= i; j++)
    {
      cout << l << "0";
      l++;
    }
    for(j = 1; j <= i; j++)
    {
      cout << r;
      if(j < i)
        cout << "0";
      r++;
    }
    r = r - (i - 1) * 2 - 1;
    cout << endl;
  }
  return 0;
}
