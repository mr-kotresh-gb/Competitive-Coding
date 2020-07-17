/* The task is to find the minimum sum of Products of two arrays of the same size, given that k modifications are allowed on the first array.
   In each modification, one array element of the first array can either be increased or decreased by 2.

Note - the product sum is Summation (A[i]*B[i]) for all i from 1 to n where n is the size of both arrays

Input Format -> First line of the input contains n and k delimited by whitespace
                Second line contains the Array A (modifiable array) with its values delimited by spaces
                Third line contains the Array B (non-modifiable array) with its values delimited by spaces

Output Format -> Output the minimum sum of products of the two arrays

Constraints:
1 ≤ N ≤ 10^5
0 ≤ |A[i]|, |B[i]| ≤ 10^5
0 ≤ K ≤ 10^9

Sample Test Case
Input
3 5
1 2 -3
-2 3 -5

Output -> -31  */

#include <bits/stdc++.h>
using namespace std;
long int minproduct(long int a[], long int b[], long int n, long int k)
{
	long int diff = 0, res = 0;
	long int temp;
	for (long int i = 0; i < n; i++)
	{
		long int pro = a[i] * b[i];
		res = res + pro;
		if (pro < 0 && b[i] < 0)  // b[i] is -ve
			temp = (a[i] + 2 * k) * b[i];
			
		else if (pro < 0 && a[i] < 0) // pro -ve and a[i] -ve
			temp = (a[i] - 2 * k) * b[i];
			
		else if (pro > 0 && a[i] < 0) // pro +ve and a[i] -ve
			temp = (a[i] + 2 * k) * b[i];
			
		else if (pro > 0 && a[i] > 0) // pro +ve and a[i] +ve
			temp = (a[i] - 2 * k) * b[i];
			
		long int d = abs(pro - temp);
		if (d > diff)
			diff = d;
	}
	return res - diff;
}

int main()
{
	long int n, mod;
	cin >> n >> mod;
	long int a[n], b[n];
	for (long int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (long int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << minproduct(a, b, n, mod);
	return 0;
}
