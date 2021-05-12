/*
    link: https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ code for finding count
// of string in a given 2D
// character array.
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

// utility function to search complete string from any given index of 2d char array
int internalSearch(string needle, int row, int col, string hay[], int row_max, int col_max, int xx)
{
    int found = 0;

    if (row >= 0 && row <= row_max && col >= 0 && col <= col_max && needle[xx] == hay[row][col])
    {
        char match = needle[xx];
        xx += 1;

        hay[row][col] = 0;

        if (needle[xx] == 0)
        {
            found = 1;
        }
        else
        {
            // through Backtrack searching
            // in every directions
            found += internalSearch(needle, row, col + 1, hay, row_max, col_max, xx);
            found += internalSearch(needle, row, col - 1, hay, row_max, col_max, xx);
            found += internalSearch(needle, row + 1, col, hay, row_max, col_max, xx);
            found += internalSearch(needle, row - 1, col, hay, row_max, col_max, xx);
        }
        hay[row][col] = match;
    }
    return found;
}

// Function to search the string in 2d array
int searchString(string needle, int row, int col, string str[], int row_count, int col_count)
{
    int found = 0;
    int r, c;

    for (r = 0; r < row_count; ++r)
    {
        for (c = 0; c < col_count; ++c)
        {
            found += internalSearch(needle, r, c, str, row_count - 1, col_count - 1, 0);
        }
    }
    return found;
}

// Driver code
int main()
{
    string needle = "MAGIC";
    string input[] = {
        "BBABBM",
        "CBMBBA",
        "IBABBG",
        "GOZBBI",
        "ABBBBC",
        "MCIGAM"
    };

    string str[ARRAY_SIZE(input)];
    int i;
    for (i = 0; i < ARRAY_SIZE(input); ++i)
    {
        str[i] = input[i];
    }

    cout << "count: " << searchString(needle, 0, 0, str, ARRAY_SIZE(str), str[0].size()) << endl;
    return 0;
}
