/*

    link: https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

    problem: given a string find longest palindromic subsequence
    output: length of longest palindromic subsequence

    refer DP_tut\3_LCS\6_Longest_Palindromic...

    crux of the problem: if we want to find the subsequence we use LCS
    then if want to find the palindromic then use the same string and reverse it.

*/

// ----------------------------------------------------------------------------------------------------------------------- //

int main() {
    // string s2 = reverse of s1.
    return LCS(s1, s2, n, n);
}