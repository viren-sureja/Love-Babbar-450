/*
    link (problem): https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

    sol (problem): https://www.geeksforgeeks.org/longest-prefix-also-suffix/

    link(for KMP Algorithm): https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    just read it carefully and u will understand the whole algo.
    -> for revision code is pasted at the end of file.

    LPS (full form): Longest proper Prefix which is also Suffix


    how naive algorithm works and what's the improvement ?

        naive algorithm works like start with every new char in main string and compare it with the pattern
        string and if matching fails in between start with next char in main string hence this will take
        time complexity of O(m * n).

        improvement here is we r able to do the same with O(N).


*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using pre-processing of the KMP algo

    Time Complexity : O(n)
    Auxiliary Space : O(n)
*/
int lps(string s)
{
    int m = s.size();
    int lps_array[m];
    lps_array[0] = 0;
    int i = 1;
    int len = 0;

    while (i < m) {
        if (s[i] == s[len]) {
            len++;
            lps_array[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps_array[len - 1];
            }
            else {
                lps_array[i] = 0;
                i++;
            }
        }

    }
    return lps_array[m - 1];

    // if we were to return non-overlapping part then
    // ans = lps_array[n-1];
    // return (ans > n / 2) ? ans / 2 : ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    increase length till it matches, but if not arrange i acc. to the length
    TC: O(N)
    SC: O(1)
*/
int largest_prefix_suffix(const std::string
    & str)
{

    int n = str.length();

    // if n is less than 2
    if (n < 2) {
        return 0;
    }

    int len = 0;
    int i = 1;

    // Iterate i till n
    while (i < n)
    {

        // If str[i] is equal to
        // str[len]
        if (str[i] == str[len])
        {
            ++len;
            ++i;
        }
        else
        {
            i = i - len + 1;
            len = 0;
        }
    }

    // if overlapping is not allowed
    // return len > n / 2 ? len / 2 : len;


    return len;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    KMP algorithm

    TC: O(N)
*/

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}






