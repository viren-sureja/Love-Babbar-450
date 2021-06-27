/*
	link: https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using vector
	TC: O(N logN)
	SC: O(N)
*/
// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
	// final sequence stored in the vector
	vector<int> finalSequence;

	// sort the original array
	// so that we can retrieve
	// the large elements from
	// the end of array elements
	sort(a, a + n);

	// In this loop first we will insert
	// one smallest element not entered
	// till that time in final sequence
	// and then enter a highest element
	// (not entered till that time) in
	// final sequence so that we
	// have large difference value. This
	// process is repeated till all array
	// has completely entered in sequence.
	// Here, we have loop till n/2 because
	// we are inserting two elements at a
	// time in loop.
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}

	// If there are odd elements, push the
	// middle element at the end.
	if (n % 2 != 0)
		finalSequence.push_back(a[n / 2]);

	// variable to store the
	// maximum sum of absolute
	// difference
	int MaximumSum = 0;

	// In this loop absolute difference
	// of elements for the final sequence
	// is calculated.
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum = MaximumSum + abs(finalSequence[i] -
			finalSequence[i + 1]);
	}

	// absolute difference of last element
	// and 1st element
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] -
		finalSequence[0]);

// return the value
	return MaximumSum;
}

// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
	more efficient
	TC: O(N logN)
	SC: O(1)
*/
int MaxSumDifference(int a[], int n) {
	sort(a, a + n);

	int ans = 0;

	/*
		if odd let's say n=7 then 7/2 = 3, till 2 in for loop.
		if even let's say n=8 then 8/2 = 4, till 3 in for loop.
	*/
	for (int i = 0; i < n / 2; i++) {
		int diff = abs(a[i] - a[n - 1 - i]);

		// as if we have ran all for loop all diff would have repeated hence double it everytime,
		// while middle ele. would have abs value 0.
		ans += diff * 2;
	}
	return ans;
}
