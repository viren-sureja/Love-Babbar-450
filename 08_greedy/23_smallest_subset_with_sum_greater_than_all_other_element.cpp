/*
	link: https://www.geeksforgeeks.org/smallest-subset-sum-greater-elements/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	another approach
*/
int minElements(int arr[], int n)
{
	// calculating HALF of array sum
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + arr[i];

	// sort the array in descending order.
	sort(arr, arr + n, greater<int>());

	int otherSum = 0;
	int i = 0;
	int res = 0;

	while (otherSum <= sum) {
		otherSum += arr[i];
		sum -= arr[i];
		res++;
	}
	return res;
}






// ----------------------------------------------------------------------------------------------------------------------- //
// function to find minimum elements needed.
int minElements(int arr[], int n)
{
	// calculating HALF of array sum
	int halfSum = 0;
	for (int i = 0; i < n; i++)
		halfSum = halfSum + arr[i];
	halfSum = halfSum / 2;

	// sort the array in descending order.
	sort(arr, arr + n, greater<int>());

	int res = 0, curr_sum = 0;
	for (int i = 0; i < n; i++) {

		curr_sum += arr[i];
		res++;

		// current sum greater than sum
		if (curr_sum > halfSum)
			return res;
	}
	return res;
}
