/*
    link: https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find
// smallest window containing
// all characters of a pattern.
#include <bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

// Function to find smallest
// window containing
// all characters of 'pat'
string findSubString(string str, string pat)
{
    int len1 = str.length();
    int len2 = pat.length();

    // Check if string's length
    // is less than pattern's
    // length. If yes then no such
    // window can exist
    if (len1 < len2) {
        cout << "No such window exists";
        return "";
    }

    int hash_pat[no_of_chars] = { 0 };
    int hash_str[no_of_chars] = { 0 };

    // Store occurrence ofs characters
    // of pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;

    int start = 0, start_index = -1, min_len = INT_MAX;

    // Start traversing the string
    // Count of characters
    int count = 0;
    for (int j = 0; j < len1; j++) {

        // Count occurrence of characters
        // of string
        hash_str[str[j]]++;

        // If string's char matches with
        // pattern's char
        // then increment count
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;

        // if all the characters are matched
        if (count == len2) {

            // Try to minimize the window
            while (hash_str[str[start]]
    > hash_pat[str[start]]
                || hash_pat[str[start]] == 0) {

                if (hash_str[str[start]]
    > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }

            // update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    // If no window found
    if (start_index == -1) {
        cout << "No such window exists";
        return "";
    }

    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}

// Driver code
int main()
{
    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest window is : \n"
        << findSubString(str, pat);
    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    sliding window technique
*/
#include <bits/stdc++.h>
using namespace std;

// Function
string Minimum_Window(string s, string t)
{

    int m[256] = { 0 };

    // Answer
    int ans = INT_MAX; // length of ans
    int start = 0; // starting index of ans
    int count = 0;
    // creating map
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    // References of Window
    int i = 0;
    int j = 0;

    // Traversing the window
    while (j < s.length()) {
        // Calculations
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        // Condition matching
        if (count == 0) {
            while (count == 0) {
                // Soring ans
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I

                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}

main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "-->Smallest window that contain all charcter : " << endl;
    cout << Minimum_Window(s, t);
}
