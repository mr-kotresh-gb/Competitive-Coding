/* A positive integer d is said to be a factor of another positive integer N if when N is divided by d,
   the remainder obtained is zero. For example, for number 12, there are 6 factors 1, 2, 3, 4, 6, 12.
   Every positive integer k has at least two factors, 1 and the number k itself.
   Given two positive integers N and K, write a program to print the kth largest factor of N.

Input Format -> The first line of input contains comma separated list of positive integer pairs(N, K)

Output Format -> Print the kth highest factor of N. If N does not have k factors, the output should be 1.

Constraints
1 < N < 10000000000.
1 < K < 600

Sample Input -> 12 3

Sample Output -> 4

Explanation:
N is 12, K is 3.
The factors of 12 are (1, 2, 3, 4, 6, 12 , the highest factor is 12, the second highest factor is 6 and the third highest factor is 4.
Hence, the output is 4.    */

#include <iostream>
using namespace std;
int main() 
{
	unsigned int n, k, i, count = 0;
	cin >> n >> k;
	if(k == 1)
		cout << n;
	else
	{
		k--;
		for(i = n / 2; i >= 1; i--)
		{
  			if((n % i) == 0)
  			count++;
  			if(count == k)
  			{
  				cout << i;
  				break;
  			}
		}
		if(count != k)
 			cout << "1";
 	}
	return 0;
}
