/*
	link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N)
*/
bool solve(int idx, int sum, vector<int>& ans, int arr[], int N) {
	// if sum is already less than 0 or index is out of bound
	if (sum < 0 || idx >= N) return false;

	// if we get perfect sum ==0 means we got the combination
	if (sum == 0) return true;

	// if try to push current elem.
	ans.push_back(arr[idx]);

	// if current element worked
	if (solve(idx + 1, sum - arr[idx], ans, arr, N)) return true;

	// if curr ele didn't work pop it
	ans.pop_back();


	// basically ignoring the current ele and going for other combination
	return solve(idx + 1, sum, ans, arr, N);
}

int equalPartition(int N, int arr[])
{
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}

	// just in case to get partition
	vector<int> ans;

	// if sum is odd it is not possible to separate no.(s)
	// eg. sum = 11, now there exist no two such group whose individual total would be same and
	// overall total will be 11
	return sum % 2 == 0 && solve(0, sum / 2, ans, arr, N);
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
	alternate solution
*/
bool solve(int arr[], int curr, int sum, int idx, int N) {
	if (curr > sum || idx >= N) return false;
	if (curr == sum) return true;

	// taking the current element
	if (solve(arr, curr + arr[idx], sum, idx + 1, N)) return true;

	// ignoring the current element
	if (solve(arr, curr, sum, idx + 1, N)) return true;

	return false;
}

int equalPartition(int N, int arr[])
{
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}

	return sum % 2 == 0 && solve(arr, 0, sum / 2, 0, N);
}