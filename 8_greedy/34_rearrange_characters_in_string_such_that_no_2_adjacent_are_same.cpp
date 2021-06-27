/*
	link: https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems

	sol (refer codes here): https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using const. size array
	TC: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& sum, int total) {
	// we cannot separate them
	if (sum.size() == 1) return 0;

	// if current count is greater than rest of the sum, means we cannot separate min. one pair of char
	// hence return 0.
	for (int i = 0; i < sum.size(); i++) {
		int temp = total - sum[i];
		if (sum[i] > temp) return 0;
	}
	return 1;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = s.size();

		int cnt[26] = { 0 };

		// get count of every char
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}

		vector<int> sum;
		int total = 0;

		// for positive count push to sum vector and calculate total as well
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				sum.push_back(cnt[i]);
				total += cnt[i];
			}
		}

		cout << check(sum, total) << endl;
	}
}
