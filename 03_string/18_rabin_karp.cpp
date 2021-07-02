/*
    link: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

    how naive algorithm works and what's the improvement ?

        naive algorithm works like start with every new char in main string and compare it with the pattern
        string and if matching fails in between start with next char in main string hence this will take
        time complexity of O(m * n).

        now improvement here is using rabin karp algo. we can do it in O(m+n) considering avg. and best case
        (while the pattern and sub-string in main string will not match).


    video: https://youtu.be/IqrPGlvI9LY

    here simple hashing function would be
    current_hash_value - ascii_of_char_we_want_to_discard + ascii_of_char_we_want_to_add
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity:
        The average and best-case running time of the Rabin-Karp algorithm is O(n+m),
        but its worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs when all characters
        of pattern and text are same as the hash values of all the substrings of txt[] match with hash
        value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.
*/


/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

/* Driver code */
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    // A prime number
    int q = 101;

    // Function Call
    search(pat, txt, q);
    return 0;
}
