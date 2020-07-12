/* Given a number ‘N’, find all the possible divisors and print them in increasing order.

Input Format -> The first line of input contains an integer 'N' denoting the number.

Output Format -> Print a line containing all the divisors in increasing order separated by space.

Constraints -> (1 <= N <= 10^8)

Sample Input -> 10

Sample Output -> 1 2 5 10 */

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
  int n, i;
  cin >> n;
  vector<int> v;
  for(i = 1; i <= sqrt(n); i++)
  {
    if(n%i == 0)
    {
		if(n / i == i)
        {
          cout << i << " ";
        }
      else{
        cout << i << " ";
        v.push_back(n / i);
      }
    }
  }
  for(i = v.size()-1; i >= 0; i--) // Here i++ leads to the segmentation fault
  {
    cout << v[i] << " ";
    v.pop_back();
  }
  return 0;
}
