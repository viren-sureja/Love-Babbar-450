/*
    link: https://practice.geeksforgeeks.org/problems/middle-of-three2926/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(1)
*/
int middle(int A, int B, int C) {
        //code here//Position this line where user code will be pasted.
    int sum = A + B + C;
    sum -= min({ A, B, C }) + max({ A, B, C });
    return sum;
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(1)
*/
int middle(int A, int B, int C) {
    if (A < B) {
        return (A > C) ? A : min(C, B);
    }
    return (A < C) ? A : max(B, C);
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    similar solution as above.
    TC: O(1)
*/
int middle(int A, int B, int C) {
    if (A < B)
        return (B < C) ? B : max(A, C);
    return (A < C) ? A : max(B, C);
}