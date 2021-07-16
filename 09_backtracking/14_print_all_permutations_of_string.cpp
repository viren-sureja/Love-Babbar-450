/*
	link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

	sol: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	here duplicate will also be included

	Time Complexity:
	O(n*n!) The time complexity is the same as the above approach,
	i.e. there are n! permutations and it requires O(n) time to print a permutation.
*/

// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int l, int r)
{
	// Base case
	if (l == r)
		cout << a << endl;
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r);

			//backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string str = "ABC";
	int n = str.size();
	permute(str, 0, n - 1);
	return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
	by ignoring element every time
	(but here duplicate wont print)

	Time Complexity:
	O(n*n!) The time complexity is the same as the above approach,
	i.e. there are n! permutations and it requires O(n) time to print a permutation.
*/
#include <bits/stdc++.h>
#include <string>
using namespace std;

void permute(string s, string answer)
{
	if (s.length() == 0)
	{
		cout << answer << " ";
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0, i);
		string right_substr = s.substr(i + 1);
		string rest = left_substr + right_substr;
		permute(rest, answer + ch);
	}
}

int main()
{
	string s;
	string answer = "";

	cout << "Enter the string : ";
	cin >> s;

	cout << "\nAll possible strings are : ";
	permute(s, answer);
	return 0;
}
