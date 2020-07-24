/* Zoya has developed a new game called Zombie World. The objective of the game is to kill all zombies in a given amount of time.
   More formally 1st input is the number of test cases.
   2nd input N represents the total number of zombies in the current level.
   3rd input T represents the maximum time allowed for the current level
   4th input P represents the initial energy level a player starts with Ei defines the energy of the i-th zombie. ( Number of Ei inputs depends on N) 
   Last input D defines the minimum energy the player needs, to advance to the next level
   
   When a player energy is greater than or equal to the i-th zombie's energy, the player wins. Upon winning, the player will be awarded with an additional
   energy equal to the difference between current zombie energy and the player energy. One unit of time will be taken to complete the fight with a single zombie.
   Rules of the game:- At any given time, a player can fight with only one zombie - Player is allowed to choose any one zombie to fight with.
   Your task is to determine whether the player will advance to the next level or not, if he plays optimally.

Input Format:
Line 1 contains an Integer denoting number of test cases
Line 2 contains an integer denoting No. of Zombies and Maximum time
Line 3 contains an integer denoting energy of Zombies
Line 4 contains an integer denoting Initial energy and Minimum energy required for next level

Output Format:
Print "YES" if a player can advance to the next level else print "NO".

Constraints:
1<=t<=10
1<=N<=50
1<=T<=100
1<=P<=100
1<=Ei<=2000
1<=D<=500

Sample Test Case:
Input:
1
2 3
4 5
5 7

Output:
YES  */


#include <algorithm> 
#include <iostream>
using namespace std;

int main()
{
	int n, time, z[20], player, min, i, test, check=0;
 	cin >> test;	//No. of test cases
 	while(test--)
 	{
  		cin >> n >> time;	//No. of zombies & max time
  		for(i = 0; i < n; i++)
   			cin >> z[i];	//energy of zombies
  		cin >> player >> min;	//initial energy and minimum energy required for next level
  		if(time < n)	//if given time is less than no.of zombie the player can not complete the level
   			check++;
   		else
   		{
   			sort(z, z + n);
  			for(i = 0; i < n; i++)
  			{
   				if(player >= z[i])
    				player += (player - z[i]);	//if player wins player gains the diffrence of energy
   				else
   				{
    				check++;
    				break;
   				}
  			}
		}
   		(player >= min && !check) ? cout << "YES" : cout << "NO";;	//check energy for next level
 		check=0;
 	}
 	return 0;
}
