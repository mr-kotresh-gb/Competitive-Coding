/* A futuristic company is building an autonomous car. The scientists at the company are training the car to perform Reverse parking.
  To park, the car needs to be able to move in backward as well as the forward direction. The car is programmed to move backward B meters and forwards again,
  say F meters, in a straight line. The car does this repeatedly until it is able to park or collides with other objects. The car covers 1 meter in T units of time.
  There is a wall after distance D from car's initial position in the backward direction. The car is currently not without defects and hence often hits the wall.
  The scientists are devising a strategy to prevent this from happening.
  Your task is to help the scientists by providing them with exact information on amount of time available before the car hits the wall.

Input Format -> First line contains an integer N denoting total number of test cases
                Next N lines containing 4 values delimited by space F B T D, where F denotes forward displacement in meters
                                                                                   B denotes backward displacement in meters
                                                                                   T denotes time taken to cover 1 meter and 
                                                                                   D denotes distance from Car's starting position and the wall in backward direction

Output Format -> 
For each test case print time taken by the Car to hit the wall
If the test case is not valid, then print "Invalid test case".
If car is not able to park, then print "Cannot park".

Constraints -> 
First move will always be in backward direction
(1 <= N <= 100)
backward displacement > forward displacement i.e. (B > F)
forward displacement (F) > 0
backward displacement (B) > 0
time (T) > 0
distance (D) > 0

Sample Test Case 1:
Input:
2
6 9 3 18
3 7 5 20
Output:
162
220

Sample Test Case 2:
Input:
1
2 2 3 10
Output:
Cannot park         */

#include<iostream>
using namespace std;
int main()
{
    int n;
    int f, b, t, d;
   	cin >> n;
    if(n > 0)
    {
    	while(n--)
    	{
    		cin >> f >> b >> t >> d;
    		int count = 0;
    		int dist = 0;
    		int ans = 0;
    		if(f >= b || d == 0 || t == 0)
        		cout << "Cannot park\n";
    		else
    		{
        		while(1)
        		{
            		if(dist + b < d)    //distanced covered+b<d
      					dist += b;    //backward move
      				else   
      				{   
          				ans = (d - dist) * t;    //remaining distance*t 
          				break;  
      				}
      				dist -= f;    //forwared move
      				count++;    //count no. of bacward and forward
     			}
     			ans += (count * t) * (f + b);    //total time
     			cout << ans << endl;
    		}
    	}
    }
    else
    {
        cout << "Invalid test case";
    }
    return 0;
}
