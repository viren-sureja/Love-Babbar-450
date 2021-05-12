/*
    link: https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

    sol: https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;

// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
    int n = str.length();

    // Count all distinct characters.
    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++) {
        hash_map[str[i]]++;
    }

    dist_count = hash_map.size();
    int size = INT_MAX;
    string res;
    // Now follow the algorithm discussed in below
    for (int i = 0; i < n; i++) {
        int count = 0;
        int visited[256] = { 0 };
        string sub_str = "";
        for (int j = i; j < n; j++) {
            if (visited[str[j]] == 0) {
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            res = sub_str;
            size = res.length();
        }
    }
    return res;
}

// Driver Code
int main()
{
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
        " characters is: "
        << findSubString(str);
    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;

// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
    int n = str.length();

    // Count all distinct characters.
    int dist_count = 0;
    bool visited[MAX_CHARS] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }

    // Now follow the algorithm discussed in below
    // post. We basically maintain a window of characters
    // that contains all characters of given string.
    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    int curr_count[MAX_CHARS] = { 0 };
    for (int j = 0; j < n; j++) {
        // Count occurrence of characters of string
        curr_count[str[j]]++;

        // If any distinct character matched,
        // then increment count
        if (curr_count[str[j]] == 1)
            count++;

        // if all the characters are matched
        if (count == dist_count) {
            // Try to minimize the window i.e., check if
            // any character is occurring more no. of times
            // than its occurrence in pattern, if yes
            // then remove it from starting and also remove
            // the useless characters.
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }

            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}

// Driver code
int main()
{
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
        " characters is: "
        << findSubString(str);
    return 0;
}
