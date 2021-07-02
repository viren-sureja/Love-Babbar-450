/*
	link: https://practice.geeksforgeeks.org/problems/smallest-number5829/1

	sol: https://www.geeksforgeeks.org/find-smallest-number-with-given-number-of-digits-and-digit-sum/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find the smallest number that can be
// formed from given sum of digits and number of digits.
#include <iostream>
using namespace std;

// Prints the smallest possible number with digit sum 's'
// and 'm' number of digits.
void findSmallest(int m, int s)
{
	// If sum of digits is 0, then a number is possible
	// only if number of digits is 1.
	if (s == 0)
	{
		(m == 1) ? cout << "Smallest number is " << 0
			: cout << "Not possible";
		return;
	}

	// Sum greater than the maximum possible sum.
	if (s > 9 * m)
	{
		cout << "Not possible";
		return;
	}

	// Create an array to store digits of result
	int res[m];

	// deduct sum by one to account for cases later
	// (There must be 1 left for the most significant
	// digit)
	s -= 1;

	// Fill last m-1 digits (from right to left)
	for (int i = m - 1; i > 0; i--)
	{
		// If sum is still greater than 9,
		// digit must be 9.
		if (s > 9)
		{
			res[i] = 9;
			s -= 9;
		}
		else
		{
			res[i] = s;
			s = 0;
		}
	}

	// Whatever is left should be the most significant
	// digit.
	res[0] += s + 1; // The initially subtracted 1 is
	// incorporated here.

	cout << "Smallest number is ";
	for (int i = 0; i < m; i++)
		cout << res[i];
}

// Driver code
int main()
{
	int s = 9, m = 2;
	findSmallest(m, s);
	return 0;
}
