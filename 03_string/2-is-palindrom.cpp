/*
	link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// method 1
class Solution {
public:


	int isPlaindrome(string s)
	{
		// Your code goes here
		int len = s.size();
		for (int i = 0;i < len / 2;i++) {
			if (s[i] != s[len - i - 1]) return 0;
		}
		return 1;
	}

};



// ----------------------------------------------------------------------------------------------------------------------- //
// method 2
class Solution {
public:


	int isPlaindrome(string s)
	{
		// Your code goes here
		string temp = s;
		reverse(temp.begin(), temp.end());
		return (temp == s);
	}

};