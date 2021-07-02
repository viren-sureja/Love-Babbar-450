/*
	link: https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

	sort according to the departure time is crux of the problem.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// CPP to design platform for maximum stoppage
#include <bits/stdc++.h>
using namespace std;

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
	// declaring vector of pairs for platform
	vector<pair<int, int> > vect[n + 1];

	// Entering values in vector of pairs
	// as per platform number
	// make departure time first element
	// of pair
	for (int i = 0; i < m; i++)
		vect[arr[i][2]].push_back(
			make_pair(arr[i][1], arr[i][0]));

	// sort trains for each platform as per
	// dept. time
	for (int i = 0; i <= n; i++)
		sort(vect[i].begin(), vect[i].end());

	// perform activity selection approach
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if (vect[i].size() == 0)
			continue;

		// first train for each platform will
		// also be selected
		int x = 0;
		count++;
		for (int j = 1; j < vect[i].size(); j++) {
			if (vect[i][j].second >=
				vect[i][x].first) {
				x = j;
				count++;
			}
		}
	}
	return count;
}

// driver function
int main()
{
	int arr[m][3] = { 1000, 1030, 1,
					  1010, 1020, 1,
					  1025, 1040, 1,
					  1130, 1145, 2,
					  1130, 1140, 2
	};
	cout << "Maximum Stopped Trains = "
		<< maxStop(arr);
	return 0;
}
