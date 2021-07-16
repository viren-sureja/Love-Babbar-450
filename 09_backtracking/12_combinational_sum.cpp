/*
	link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

	sol: https://www.geeksforgeeks.org/combinational-sum/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find all combinations that
// sum to a given value
#include <bits/stdc++.h>
using namespace std;

// Print all members of ar[] that have given
void findNumbers(vector<int>& ar, int sum,
	vector<vector<int> >& res, vector<int>& r,
	int i)
{
	// if we get exact answer
	if (sum == 0) {
		res.push_back(r);
		return;
	}

	// Recur for all remaining elements that
	// have value smaller than sum.
	while (i < ar.size() && sum - ar[i] >= 0) {

		// Till every element in the array starting
		// from i which can contribute to the sum
		r.push_back(ar[i]); // add them to list

		// recur for next numbers
		findNumbers(ar, sum - ar[i], res, r, i);
		i++;

		// Remove number from list (backtracking)
		r.pop_back();
	}
}

// Returns all combinations
// of ar[] that have given
// sum.
vector<vector<int> > combinationSum(vector<int>& ar,
	int sum)
{
	// sort input array
	sort(ar.begin(), ar.end());

	// remove duplicates
	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<int> r;
	vector<vector<int> > res;
	findNumbers(ar, sum, res, r, 0);

	return res;
}

// Driver code
int main()
{
	vector<int> ar;
	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(8);
	int n = ar.size();

	int sum = 8; // set value of sum
	vector<vector<int> > res = combinationSum(ar, sum);

	// If result is empty, then
	if (res.size() == 0) {
		cout << "Emptyn";
		return 0;
	}

	// Print all combinations stored in res.
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}
}









// ----------------------------------------------------------------------------------------------------------------------- //
/*
	alternate solution
*/
vector<vector<int>> ans;

void solve(int idx, vector<int> currVec, int sum, vector<int>& v, int B) {
	if (sum > B || idx >= v.size()) return;

	if (sum == B) {
		ans.push_back(currVec);
		return;
	}

	while (idx < v.size() && sum <= B) {

		currVec.push_back(v[idx]);

		if (v[idx] + sum <= B) solve(idx, currVec, sum + v[idx], v, B);

		currVec.pop_back();

		idx++;
	}
}


vector<vector<int>> combinationSum(vector<int>& A, int B) {

	ans.clear();

	set<int> s;
	for (int i : A) s.insert(i);

	vector<int> v(s.begin(), s.end());

	solve(0, {}, 0, v, B);

	return ans;
}
