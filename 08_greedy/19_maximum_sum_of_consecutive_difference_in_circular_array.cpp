/*
	link: https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	short and efficient
	TC: O(N)
	SC: O(1)
*/
long long int maxSum(int arr[], int n)
{
	long long int sum = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n / 2; i++)
	{
		sum -= (2 * arr[i]);
		sum += (2 * arr[n - i - 1]);
	}
	return sum;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N)
	SC: O(N)
*/
typedef long long int lli;

long long int maxSum(int arr[], int n)
{
	sort(arr, arr + n);

	int newArr[n], j = 0;
	lli sum = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		newArr[j] = arr[i];
		j += 2;
	}

	j = 1;
	for (int i = n - 1; i >= n / 2; i--) {
		newArr[j] = arr[i];
		j += 2;
	}

	for (int i = 0; i < n - 1; i++) {
		sum += abs(newArr[i] - newArr[i + 1]);
	}

	sum += abs(newArr[0] - newArr[n - 1]);
	return sum;
}