/* The problem solvers have found a new Island for coding and named it as Philaland. These smart people were given a task to make a purchase of items at the Island
   easier by distributing various coins with different values. Manish has come up with a solution that if we make coins category starting from $1 till the maximum
   price of the item present on Island, then we can purchase any item easily. He added the following example to prove his point.
   
   Lets suppose the maximum price of an item is 5$ then we can make coins of {$1, $2, $3, $4, $5}to purchase any item ranging from $1 till $5.

   Now Manisha, being a keen observer suggested that we could actually minimize the number of coins required and gave following distribution
   {$1, $2, $3}. According to him any item can be purchased one time ranging from $1 to $5. Everyone was impressed with both of them.
   Your task is to help Manisha come up with a minimum number of denominations for any arbitrary max price in Philaland.

Input Format ->
# First line contains an integer T denoting the number of test cases.
# Next T lines contains an integer N denoting the maximum price of the item present on Philaland.

Output Format -> For each test case print a single line denoting the minimum number of denominations of coins required.

Constraints -> (1 <= T <= 100), (1 <= N <= 5000)

Sample Input:
2
10
5

Sample Output:
4
3

Explanation:
For test case 1, N=10.
According to Manish {$1, $2, $3,… $10} must be distributed.
But as per Manisha only {$1, $2, $3, $4} coins are enough to purchase any item ranging from $1 to $10. Hence minimum is 4.
Likewise denominations could also be {$1, $2, $3, $5}. Hence answer is still 4.
For test case 2, N=5.
According to Manish {$1, $2, $3, $4, $5} must be distributed.
But as per Manisha only {$1, $2, $3} coins are enough to purchase any item ranging from $1 to $5. Hence minimum is 3.
Likewise denominations could also be {$1, $2, $4}. Hence answer is still 3. */

#include<iostream>
using namespace std;

int main()
{
  // Getting the value of test cases from the user
  int T;
  cin >> T;
  // Iterating the test cases
  for (int i = 1; i <= T; i++)
  {
    //Getting the coin values from user
    int N, count = 0;
    cin >> N;
    
    while (N != 0)
    {
      count++;
      N = N >> 1; // Runs faster than arithmatic operators
    }
    
    cout << count << endl;
  }
  return 0;
}
