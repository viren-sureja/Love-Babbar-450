/*
    link: https://practice.geeksforgeeks.org/problems/interleaved-strings/1

    although its LCS variation but tweaked code of it will not work here.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

bool isInterleave(string A, string B, string C)
{
    // Find lengths of the two strings
    int M = A.size(), N = B.size();

    // Let us create a 2D table to store solutions of
    // subproblems. C[i][j] will be true if C[0..i+j-1]
    // is an interleaving of A[0..i-1] and B[0..j-1].
    bool IL[M + 1][N + 1];

    memset(IL, 0, sizeof(IL)); // Initialize all values as false.

    // C can be an interleaving of A and B only of sum
    // of lengths of A & B is equal to length of C.
    if ((M + N) != C.size())
        return false;

        // Process all characters of A and B
    for (int i = 0; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            // two empty strings have an empty string
            // as interleaving
            if (i == 0 && j == 0)
                IL[i][j] = true;

            // A is empty
            else if (i == 0 && B[j - 1] == C[j - 1])
                IL[i][j] = IL[i][j - 1];

            // B is empty
            else if (j == 0 && A[i - 1] == C[i - 1])
                IL[i][j] = IL[i - 1][j];

            // Current character of C matches with current character of A,
            // but doesn't match with current character of B
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                IL[i][j] = IL[i - 1][j];

            // Current character of C matches with current character of B,
            // but doesn't match with current character of A
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                IL[i][j] = IL[i][j - 1];

            // Current character of C matches with that of both A and B
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                IL[i][j] = (IL[i - 1][j] || IL[i][j - 1]);
        }
    }

    return IL[M][N];
}

// ----------------------------------------------------------------------------------------------------------------------- //