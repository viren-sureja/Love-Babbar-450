/*
	link: https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

	sol: https://www.geeksforgeeks.org/find-minimum-maximum-amount-buy-n-candies/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N log N)
*/
int findMinimum(int arr[], int n, int k)
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		// Buy current candy
		res += arr[i];

		// And take k candies for free
		// from the last
		n = n - k;
	}
	return res;
}

int findMaximum(int arr[], int n, int k)
{
	int res = 0, index = 0;

	for (int i = n - 1; i >= index; i--)
	{
		// Buy candy with maximum amount
		res += arr[i];

		// And get k candies for free from
		// the starting
		index += k;
	}
	return res;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N logN)
*/
vector<int> candyStore(int candies[], int N, int K)
{
	sort(candies, candies + N);

	// get index for
	int total_idx = N / (K + 1);
	if (N % (K + 1)) total_idx++;

	total_idx = min(total_idx, N);

	int mn = 0, mx = 0;

	for (int i = 0; i < total_idx; i++) {
		mn += candies[i];
	}
	for (int i = N - 1; i >= N - total_idx; i--) {
		mx += candies[i];
	}

	return { mn, mx };
}