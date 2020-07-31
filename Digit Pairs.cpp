/* Given N three-digit numbers, your task is to find bit score of all N numbers and then print the number of pairs possible based on these calculated bit score.

1.Rule for calculating bit score from three digit number:
  From the 3-digit number, extract largest digit and multiply by 11 then
  extract smallest digit multiply by 7 then add both the result for getting bit pairs.

Note:- Bit score should be of 2-digits, if above results in a 3-digit bit score, simply Ignore most significant digit.

Consider following examples.
Say, number is 286
Largest digit is 8 and smallest digit is 2
So, 8*11+2*7 = 102. So, ignore most significant bit, So bit score = 02.
Say, Number is 123
Largest digit is 3 and smallest digit is 1.
So, 3*11+7*1 = 40, So bit score is 40.

2. Rules for making pairs from above calculated bit score.
   Condition for making pairs are
- Both bit scores should be in either odd position or even position to be eligible to form a pair.
- Pairs can be only made if most significant digit are same and at most two pair can be made for a given significant digit

Constraints -> N <= 500

Input Format
First line contains an Integer N, denoting the count of numbers.
Second line contains N 3-digit integers delimites by space

Output Format
One integer value denoting the number of bit pairs

Sample Input:
8
234 567 321 345 123 110 767 111

Sample Output:
3

Explanation:
After getting the most and least significant digits of the numbers and applying the formula given in Rule 1 we get the bit scores of the numbers as
  58 12 40 76 40 11 19 18
No. of pair possible are 3
40 appears twice at odd indices 3 and 5 respectively. Hence, this is one pair.
12, 11, 18 are at even-indices. Hence, two pairs are possible from these three bit scores.
  Hence, total pairs possible is 3. */


#include<iostream>
using namespace std;

int bit_score(int n)
{
    int a, b, c, largest, smallest;
    int score;
    a = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    c = n % 10;
    n /= 10;

    largest = (a > b) ? a : b;
    largest = (c > largest) ? c : largest;
    smallest = (a < b) ? a : b;
    smallest = (c < smallest) ? c : smallest;
    score = (largest * 11) + (smallest * 7);
    score = score % 100;
    return score;
}

int findPairs(int score_array[], int N)
{
    int sig_dig[10], i, pairs = 0, msb;
    for (i = 0; i < 10; i++)
        sig_dig[i] = 0;
    for (i = 0; i < N; i = i + 2)
    {
        msb = score_array[i] / 10;
        for (int j = i + 2; j < N; j = j + 2)
        {
            if (msb == score_array[j] / 10)
            {
                if (sig_dig[msb] < 2)
                {
                    sig_dig[msb]++;
                }
            }
        }
    }

    for (i = 1; i < N; i = i + 2)
    {
        msb = score_array[i] / 10;
        for (int j = i + 2; j < N; j = j + 2)
        {
            if (msb == score_array[j] / 10)
            {
                if (sig_dig[msb] < 2)
                {
                    sig_dig[msb]++;
                }
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        pairs = pairs + sig_dig[i];
    }

    return pairs;
}

int main()
{

    int N, i;
    int ip_array[501];
    int score_array[501];
    int pairs;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> ip_array[i];
    }
    for (i = 0; i < N; i++)
    {
        score_array[i] = bit_score(ip_array[i]);
    }
    pairs = findPairs(score_array, N);
    cout << pairs;
    return 0;
}

 for(i=0; i<10; i++) {
  pairs = pairs + sig_dig[i];
 }

 return pairs;
}

int main() {
 int N, i;
 int ip_array[501];
 int score_array[501];
 int pairs;
 cin>>N;
 for(i=0; i<N; i++) {
  cin>>ip_array[i];
 }
 for(i=0; i<N; i++) {
  score_array[i] = bit_score(ip_array[i]);
 }
 pairs = findPairs(score_array, N);
 cout<<pairs;
 return 0;
}
