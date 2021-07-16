/*
	link: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

	video: https://youtu.be/5crucASFoA4
	(just to understand as it will give TLE in GFG)

	sol: https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	Time Complexity: O((n^2)^k).
	For every recursive call n^2 recursive calls is generated until
	the value of k is 0. So total recursive calls are O((n^2)^k).

	Space Complexity:O(n).
*/
void recur(
	string str, int k, string& max)
{
	// Return if no swaps left
	if (k == 0)
		return;

	int n = str.length();

	// Consider every digit
	for (int i = 0; i < n - 1; i++) {

		// Compare it with all digits after it
		for (int j = i + 1; j < n; j++) {
			// if digit at position i
			// is less than digit
			// at position j, swap it
			// and check for maximum
			// number so far and recurse
			// for remaining swaps
			if (str[i] < str[j]) {
				// swap str[i] with str[j]
				swap(str[i], str[j]);

				// If current num is more
				// than maximum so far
				if (str.compare(max) > 0)
					max = str;

				// recurse of the other k - 1 swaps
				recur(str, k - 1, max);

				// Backtrack
				swap(str[i], str[j]);
			}
		}
	}
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(n^k).
	For every recursive call n recursive calls is generated until
	the value of k is 0. So total recursive calls are O((n)^k).

	SC: O(N)
*/

// C++ program to find maximum
// integer possible by doing
// at-most K swap operations on
// its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap operations
// on its digits
void findMaximumNum(
	string str, int k,
	string& max, int ctr)
{
	// return if no swaps left
	if (k == 0)
		return;

	int n = str.length();

	// Consider every digit after
	// the cur position
	char maxm = str[ctr];
	for (int j = ctr + 1; j < n; j++) {
		// Find maximum digit greater
		// than at ctr among rest
		if (maxm < str[j])
			maxm = str[j];
	}

	// If maxm is not equal to k,
	// decrement k
	if (maxm != str[ctr])
		--k;

	// search this maximum among the rest
	for (int j = ctr; j < n; j++) {
		// If digit equals maxm swap
		// the digit with current
		// digit and recurse for the rest
		if (str[j] == maxm) {
			// swap str[ctr] with str[j]
			swap(str[ctr], str[j]);

			// If current num is more than
			// maximum so far
			if (str.compare(max) > 0)
				max = str;

			// recurse other swaps after cur
			findMaximumNum(str, k, max, ctr + 1);

			// Backtrack
			swap(str[ctr], str[j]);
		}
	}
}

// Driver code
int main()
{
	string str = "129814999";
	int k = 4;

	string max = str;
	findMaximumNum(str, k, max, 0);

	cout << max << endl;

	return 0;
}
