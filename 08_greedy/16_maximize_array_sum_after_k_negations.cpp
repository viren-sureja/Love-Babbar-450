/*
	link: https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1

	sol: https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	Time Complexity: O(k*n)
	Auxiliary Space: O(1)
*/
int maximumSum(int arr[], int n, int k)
{
	// Modify array K number of times
	for (int i = 1; i <= k; i++)
	{
		int min = INT_MAX;
		int index = -1;

		// Find minimum element in array for
		// current operation and modify it
		// i.e; arr[j] --> -arr[j]
		for (int j = 0; j < n; j++)
		{
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}

		// this the condition if we find 0 as
		// minimum element, so it will useless to
		// replace 0 by -(0) for remaining operations
		if (min == 0)
			break;

		// Modify element of array
		arr[index] = -arr[index];
	}

	// Calculate sum of array
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
	Time Complexity: O(n*logn)
	Auxiliary Space: O(1)
*/
int sol(int arr[], int n, int k)
{
	int sum = 0;
	int i = 0;

	// Sorting given array using in-built
	// sort function
	sort(arr, arr + n);
	while (k > 0)
	{
		// If we find a 0 in our
		// sorted array, we stop
		if (arr[i] >= 0)
			k = 0;
		else
		{
			arr[i] = (-1) * arr[i];
			k = k - 1;
		}
		i++;

	}

	// Calculating sum
	for (int j = 0; j < n; j++)
	{
		sum += arr[j];
	}
	return sum;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
	Time Complexity: O(n*logn)
	Auxiliary Space: O(1)
*/
long long int sumArray(long long int* arr, int n)
{
	long long int sum = 0;

	// Iterate from 0 to n - 1
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

// Function to maximize sum
long long int maximizeSum(long long int arr[], int n, int k)
{
	sort(arr, arr + n);
	int i = 0;

	// Iterate from 0 to n - 1
	for (i = 0; i < n; i++) {
		if (k && arr[i] < 0) {
			arr[i] *= -1;
			k--;
			continue;
		}
		break;
	}
	if (i == n)
		i--;

	if (k == 0 || k % 2 == 0) {
		return sumArray(arr, n);
	}

	if (abs(arr[i]) >= abs(arr[i - 1])) {
		i--;
	}

	arr[i] *= -1;
	return sumArray(arr, n);
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using priority queue (best to understand)

	TC: O(N)
	SC: O(N)
*/
int MaxSum(int a[], int n, int k)
{
	int sum = 0;

	// Create a min heap for priority queue
	priority_queue<int, vector<int>, greater<int>> pq;

	// Insert all elements in f array in priority_queue
	for (int i = 0; i < n; i++)
	{
		pq.push(a[i]);
	}

	while (k--)
	{

		// Retrieve and remove min element
		int temp = pq.top();

		pq.pop();

		// Modify the minimum element and
		// add back to priority queue
		temp = (temp) * -1;
		pq.push(temp);
	}

	// Calculate the sum
	while (!pq.empty())
	{
		sum = sum + pq.top();
		pq.pop();
	}
	return sum;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using sorting
	TC: O(N logN)
	SC: O(1)
*/
typedef long long int ll;
long long int maximizeSum(long long int a[], int n, int k)
{
	sort(a, a + n);
	ll sum = 0, i;
	for (i = 0; i < n; i++) {
		if (a[i] < 0 and k>0) {
			a[i] *= -1;
			k--;
		}
	}

	sort(a, a + n);
	for (i = 0; i < n; i++)
		sum += a[i];

	if (k & 1)
		sum -= 2 * a[0];

	return sum;
}