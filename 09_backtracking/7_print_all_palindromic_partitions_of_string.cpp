/*
	link: https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

	video: https://youtu.be/WBgsABoClE0
*/



// ----------------------------------------------------------------------------------------------------------------------- //
bool isPalindrome(string s, int start, int end) {
	while (start <= end) {
		if (s[start++] != s[end--]) return false;
	}
	return true;
}

void recur(int index, string s, vector<string>& path, vector<vector<string>>& res) {
	if (index == s.size()) {
		res.push_back(path);
		return;
	}

	for (int i = index, i < s.size(); i++) {
		if (isPalindrome(s, index, i)) {
			path.push_back(s.substr(index, i - index + 1));
			recur(i + 1, s, path, res);
			path.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> path;
	recur(0, s, path, res);
	return res;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
	another solution
*/

vector<string> vs;

// function to check palindrom
bool isPalindrome(string s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - 1 - i]) return false;
	}
	return true;
}

// recuring func.
void recur(string s, string ans) {
	// if there is nothing left to check in string
	if (s.size() == 0) {
		// substr is used just to remove extra space at the end
		// also push the ans string as it contains the all the palindromic substr
		vs.push_back(ans.substr(0, ans.size() - 1));
		return;
	}

	// checking for every partition in our current string
	for (int i = 0; i < s.size(); i++) {
		string left = s.substr(0, i + 1);

		// if left substring is palindromic then and only then
		if (isPalindrome(left)) {
			string right = s.substr(i + 1);
			// pass the right substring in s and add left to the ans
			recur(right, ans + left + " ")
		}
	}
}

vector<string> backtracking(string s) {
	vs.clear();
	int n = s.size();

	recur(s, "");
	return vs;
}