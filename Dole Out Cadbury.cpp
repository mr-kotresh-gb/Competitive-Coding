/* You are a teacher in reputed school. During Celebration Day you were assigned a task to distribute Cadbury such that
   maximum children get the chocolate. You have a box full of Cadbury with different width and height. You can only distribute largest shape Cadbury.
   So, if you have a Cadbury of length 10 and width 5, then you need to break Cadbury in 5x5 square and distribute to first child and then remaining 5x5 to next in queue.

Constraints
0<P<Q<1501
0<R<S<1501

Input Format
First line contains an integer P that denotes minimum length of Cadbury in the box
Second line contains an integer Q that denotes maximum length of Cadbury in the box
Third line contains an integer R that denotes minimum width of Cadbury in the box
Fourth line contains an integer S that denotes maximum width of Cadbury in the box.

Output Format:
Print total number of children who will get chocolate

Sample Test Case
Input
5
7
3
4

Output -> 24

Explanation
Length is in between 5 to 7 and width is in between 3 to 4.
So, we have 5X3, 5X4, 6X3, 6X4, 7X3, 7X4 type of Cadbury in the box.
If we take 5X3
First, we can give 3X3 square Cadbury to 1st child. Then we are left with 3X2. Now largest square is 2X2 which will be given to next child.
Next, we are left with two 1x1 part of cadbury which will be given to another two children.  */


#include<iostream>
using namespace std;

int no_of_children(int row, int column)
{
  int count = 0;
  int total = row * column;
  while(row && column)
  {
    count++;
    if(row > column)
      row -= column;
    else
      column -= row;
  }
  return count;
}

int main()
{
  int p, q, r, s, sum = 0;
  cin >> p >> q >> r >> s;
  if(0 < p < 1501 && 0 < q < 1501 && 0 < r < 1501 && 0 < s < 1501)
  {
    for(int i = p; i <= q; i++)
    {
      for(int j = r; j <= s; j++)
      {
        sum += no_of_children(i, j);
      }
    }
  }
  cout << sum;
  return 0;
}
