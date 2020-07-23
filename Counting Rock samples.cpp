/* Juan Marquinhos is a geologist and he needs to count rock samples in order to send it to a chemical laboratory.
   He has a problem: The laboratory only accepts rock samples by a range of its size in ppm (parts per million).
   Juan Marquinhos receives the rock samples one by one and he classifies the rock samples according to the range of the laboratory.
   This process is very hard because the number of rock samples may be in millions.
   
   Juan Marquinhos needs your help, your task is to develop a program to get the number of rocks in each of the ranges accepted by the laboratory.

Input Format -> A positive integer 'S' denoting the number of rock samples separated by a blank space,
                and a positive integer 'R' denoting the number of ranges of the laboratory;
                A list of the sizes of S samples as positive integers separated by space,
                R lines where the line containing two positive integers, space separated,
                indicating the minimum size and maximum size respectively of the range.

Output Format -> R lines where the line containing a single non-negative integer indicating the number of the samples which lie in the range.

Constraints
10 <= S <= 10000
1 <= R <= 1000000
1<=size of Sample <= 1000

Sample Input ->
10 2
345 604 321 433 704 470 808 718 517 811
300 350
400 700

Sample Output:
2 4     */


#include<iostream>
using namespace std;
int main()
{
    
    long long int size, totalRange, i, j, count = 0;
    cin >> size >> totalRange;
  	long long int S[size], range[totalRange * 2];
    for(i = 0; i < size; i++)
    {
        cin >> S[i];
    }
    totalRange = totalRange * 2;
    for(i = 0; i < totalRange; i = i + 2)
    {
        cin >> range[i] >> range[i + 1];
        for(j = 0; j < size; j++)
        {
            if((S[j] >= range[i]) && (S[j] <= range[i + 1]))
                count++;
        }
        cout << count << " ";
        count = 0;
    }
    return 0;
}
