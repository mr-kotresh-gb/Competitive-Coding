/* Given a sequence of distinct numbers a1, a2, ….. an, an inversion occurs if there are indices i aj.
   For example, in the sequence 2 1 4 3 there are 2 inversions (2 1) and (4 3). The input will be a main sequence of N positive integers.
   From this sequence, a Derived Sequence will be obtained using the following rule. The output is the number of inversions in the derived sequence.
   Rule for forming derived sequence
   An integer may be represented in base 6 notation. In base 6, 10305 is 1x64 + 3x62 + 5 =1409. Note that none of the digits in that representation will be more than 5.
   The sum of digits in a base 6 representation is the sum of all the digits at the various positions in the representation. Thus for the number 1409, the representation is 10305, and the sum of digits is 1+0+3+0+5=9. The sum of digits may be done in the decimal system, and does not need to be in base 6. The derived sequence is the sum of the digits when the corresponding integer is represented in the base 6 form number will be expressed in base 6, and the derived sequence is the sum of the digits of the number in the base 6 representation.

Input Format
The first line of the input will have a single integer, which will give N.
The next line will consist of a comma separated string of N integers, which is the main sequence

Output Format
The number of inversions in the derived sequence formed from the main sequence.

Constraints
N <= 50
Integers in sequence <= 107

Sample Input
5
55 53 88 27 33

Sample Output -> 2    */


#include<iostream>
#include<cmath>
using namespace std;

int sum(int a)
{
    int s = 0,r;
    while(a > 0)
    {
       r = a % 10;
       s += r;
       a = a / 10;
    }
    return s;
}

int main()
{
    int a[100], b[100], c[100], i, n, j, rem, s = 0, cn = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
    {
        j = 0;
        while(a[i] > 0)
        {
            rem = a[i] % 6;
            s = s + (rem * pow(10, j));
            a[i] = a[i] / 6;
            j++;
        }
        b[i] = s;
        s = 0;
    }
    for(i = 0; i < n; i++)
        c[i] = sum(b[i]);
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(c[i] > c[j])
                cn++;
        }
    }
    cout << cn;
    return 0;
}
