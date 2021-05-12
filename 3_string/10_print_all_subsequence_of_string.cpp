/*
    link: https://www.geeksforgeeks.org/print-subsequences-string/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void recur(string mainString, string curr, int i, int n) {
    if (i == n) cout << curr < endl;
    else {

        // skipping the current char at index i
        recur(mainString, curr, i + 1, n);

        // including the current char at index i
        curr += mainString[i];
        recur(mainString, curr, i + 1, n);
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
// Find all subsequences
void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }

    // output is passed with including
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);

    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}

// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";

    printSubsequence(input, output);

    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// CPP program to generate power set in
// lexicographic order.
#include <bits/stdc++.h>
using namespace std;

// str : Stores input string
// n : Length of str.
// curr : Stores current permutation
// index : Index in current permutation, curr
void printSubSeqRec(string str, int n,
    int index = -1, string curr = "")
{
    // base case
    if (index == n)
        return;

    if (!curr.empty()) {
        cout << curr << "\n";
    }

    for (int i = index + 1; i < n; i++) {

        curr += str[i];
        printSubSeqRec(str, n, i, curr);

        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}

// Generates power set in lexicographic
// order.
void printSubSeq(string str)
{
    printSubSeqRec(str, str.size());
}

// Driver code
int main()
{
    string str = "cab";
    printSubSeq(str);
    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// CPP rogram to print all subsequence of a
// given string.
#include <bits/stdc++.h>
using namespace std;

// set to store all the subsequences
unordered_set<string> st;

// Function computes all the subsequence of an string
void subsequence(string str)
{

    // Iterate over the entire string
    for (int i = 0; i < str.length(); i++)
    {

        // Iterate from the end of the string
        // to generate substrings
        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);

            // Drop kth character in the substring
            // and if its not in the set then recur
            for (int k = 1; k < sub_str.length() - 1; k++)
            {
                string sb = sub_str;

                // Drop character from the string
                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}

// Driver Code
int main()
{
    string s = "aabc";
    subsequence(s);
    for (auto i : st)
        cout << i << " ";
    cout << endl;

    return 0;
}
