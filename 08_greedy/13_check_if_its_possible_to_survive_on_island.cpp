/*
	link: https://www.geeksforgeeks.org/survival/

	Time Complexity: O(1)
	Space Complexity: O(1)
*/




// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
void survival(int S, int N, int M)
{

	// If we can not buy at least a week
	// supply of food during the first week
	// OR We can not buy a day supply of food
	// on the first day then we can't survive.
	if (((N * 6) < (M * 7) && S > 6) || M > N)
		cout << "No\n";
	else {
		// If we can survive then we can
		// buy ceil(A/N) times where A is
		// total units of food required.
		int days = (M * S) / N;
		if (((M * S) % N) != 0)
			days++;
		cout << "Yes " << days << endl;
	}
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;
	survival(S, N, M);
	return 0;
}
