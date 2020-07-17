/* For enhancing the book reading, school distributed story books to students as part of the Children’s day celebrations.
   To increase the reading habit, the class teacher decided to exchange the books every weeks so that everyone will have a different book to read.
   She wants to know how many possible exchanges are possible.
   
   If they have 4 books and students, the possible exchanges are 9. Bi is the book of i-th student and after the exchange, he should get a different book, other than Bi.

B1 B2 B3 B4 – first state, before exchange of the books
B2 B1 B4 B3
B2 B3 B4 B1
B2 B4 B1 B3
B3 B1 B4 B2
B3 B4 B1 B2
B3 B4 B2 B1
B4 B1 B2 B3
B4 B3 B1 B2
B4 B3 B2 B1
Find the number of possible exchanges, if the books are exchanged so that every student will receive a different book.

Constraints -> (1<= N <= 1000000)

Input Format -> Input contains one line with N, indicates the number of books and number of students.

Output Format -> Output the answer modulo 100000007.

Sample Input -> 4

Sample Output -> 9  */

#include<iostream> 
using namespace std;

long long int fib(long int n) 
{ 
    long long int f[n+1]; 
  long long int i; 
  f[0] = 1;   f[1] = 0;  f[2]=1;

  for (i = 3; i <= n; i++) 
      f[i] = ((i-1)*(f[i-1] + f[i-2])) % 100000007;
  
  return f[n]; 
}

int main () 
{ 
   long long int n;
  cin >> n;
  cout << fib(n); 
  return 0; 
}
