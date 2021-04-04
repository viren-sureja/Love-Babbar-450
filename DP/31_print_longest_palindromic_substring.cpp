/*
    link: https://leetcode.com/problems/longest-palindromic-substring/
    link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

    sol: https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
    sol: https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// brute force
/*
    Time complexity: O(n^3).
    Three nested loops are needed to find the longest palindromic substring in this approach, so the time complexity is O(n^3).
    Auxiliary complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length
// of the longest palindrome
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();

    // All substrings of length 1
    // are palindromes
    int maxLength = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int flag = 1;

            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            // Palindrome
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    // return length of LPS
    return maxLength;
}

// Driver Code
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
        << longestPalSubstr(str);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// DP solution 
/*
    Time complexity: O(n^2).
    Two nested traversals are needed.
    Auxiliary Space: O(n^2).
    Matrix of size n*n is needed to store the dp array.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to print a substring
// str[low..high]
void printSubStr(
    string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length of
// the longest palindrome
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();

    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1
    // are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;

                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    // return length of LPS
    return maxLength;
}

// Driver Code
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
        << longestPalSubstr(str);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
#include <bits/stdc++.h>
using namespace std;

// A utility function to print
// a substring str[low..high]
void printSubStr(char* str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

// This function prints the
// longest palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(char* str)
{
    // The result (length of LPS)
    int maxLength = 1;

    int start = 0;
    int len = strlen(str);

    int low, high;

    // One by one consider every
    // character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i) {
        // Find the longest even length palindrome
        // with center points as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len
            && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        // Find the longest odd length
        // palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len
            && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}

// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: "
        << longestPalSubstr(str)
        << endl;
    return 0;
}

/* Time complexity : O(n ^ 2), where n is the length of input string.
Nested traversal of the string is needed.So time complexity is O(n ^ 2).
Auxiliary Space : O(1) */

// ----------------------------------------------------------------------------------------------------------------------- //