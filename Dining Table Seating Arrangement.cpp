/* In a conference, attendees are invited for a dinner after the conference. The Coordinator,
   Sagar arranged round tables for dinner and want to have an impactful seating experience for the attendees.
   Before finalizing the seating arrangement, he wants to analyze all possible arrangements. There are R round tables and N attendees.
   In case where N is an exact multiple of R, the number of attendees must be exactly N/R. If N is not an exact multiple of R,
   then the distribution of attendees must be as equal as possible. Please refer to the Example section for better understanding.
   For example, R = 2 and N = 3
All possible seating arrangements are
(1,2) & (3)
(1,3) & (2)
(2,3) & (1)
Attendees are numbered from 1 to N.

Constraints
0 < R <= 10 (Integer)
0 < N <= 20 (Integer)

Input Format
The first line contains T denoting the number of test cases.
Each test case contains two space delimited integers R and N, where R denotes the number of round tables and N denotes the number of attendees.

Output Format
Single integer S denoting number of possible unique arrangements

Sample Test case:
Input
1
2 5

Output
10

Explanation
R = 2, N = 5
(1,2,3) & (4,5)
(1,2,4) & (3,5)
(1,2,5) & (3,4)
(1,3,4) & (2,5)
(1,3,5) & (2,4)
(1,4,5) & (2,3)
(2,3,4) & (1,5)
(2,3,5) & (1,4)
(2,4,5) & (1,3)
(3,4,5) & (1,2)
Arrangements like
(1,2,3) & (4,5)
(2,1,3) & (4,5)
(2,3,1) & (4,5), etc.
But, as it is a round table, all the above arrangements are same.  */


#include<iostream>
using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  for(int i = 1; i <= test_case; i++)
  {
    int tables, attendees, PA, PB, TA, TB, j;
    cin >> tables >> attendees;
    long long int fact[attendees + 2];
    long long int divide, arrange;
    //for cases where tables are greater than the number of attendees
    if(tables >= attendees)
    {
      cout << "1" << endl;
    }
    //for all other cases
    else
    {
      //find the number of attendees to be seated in each type A and type B table
      PA = attendees / tables;
      PB = PA + 1;
      //find the number of type A and type B tables
      TB = attendees % tables;
      TA = tables - TB;
      //calculating the factorial values and storing in an array
      fact[0] = 1;
      for(j = 1; j <= attendees + 1; j++)
      {
        fact[j] = j * fact[j-1];
      }
      //Dividing people between tables
      divide = fact[attendees] / (pow(fact[PA], TA) * pow(fact[PB], TB) * fact[TA] * fact[TB]);
      //Arranging the people after dividing them
      if(PB >= 4)
      {
        arrange = divide * (pow(fact[PA - 1] / 2, TA) * pow((fact[PB - 1] / 2), TB));
      }
      else
      {
        arrange = divide;
      }
	cout << arrange << endl;
    }
  }
  return 0;
}
