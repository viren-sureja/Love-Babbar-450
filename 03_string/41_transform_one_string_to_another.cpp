/*
    link: https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    eg. EACBD -> EABCD

    1st iter. : both pointer at D
    2nd: 1st at C and 2nd at C adding res = 1(to transfer that B).
    3rd: now let's assume we have B at very first pos then also still we have to
    transfer EA hence cost of that too will be counted
*/

int minOps(string& A, string& B)
{
    int m = A.length(), n = B.length();

    // This parts checks whether conversion is
    // possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++) // count characters in A
        count[B[i]]++;
    for (int i = 0; i < n; i++) // subtract count for
        count[A[i]]--;		 // every character in B
    for (int i = 0; i < 256; i++) // Check if all counts become 0
        if (count[i])
            return -1;

        // This part calculates the number of operations required
    int res = 0;
    int i = n - 1, j = n - 1;

    while (i >= 0)
    {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j])
        {
            i--;
            res++;
        }


        // If A[i] and B[j] match
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
}