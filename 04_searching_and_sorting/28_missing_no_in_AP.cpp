/*
    link: https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

    nth no. in AP = a0 + (n-1) d.

    so here (b = a + (n-1)*d) where n should be integer.

    n = (b-a)/c + 1;
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(1)
*/
int inSequence(int A, int B, int C) {

    if (C == 0) {
        if (A == B) return 1;
        else return 0;
    }

    long double ans = ((long double)B - A) / C + 1;

    return ans > 0 && ceil(ans) == floor(ans);
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    similar solution
*/
int inSequence(int A, int B, int C) {
    int d = (B - A);
    if (d == 0)
        return 1;
    if (d < 0) {
        if (C >= 0)
            return 0;
        if (d % C == 0)
            return 1;
        return 0;
    }
    else {
        if (C <= 0)
            return 0;
        if (d % C == 0)
            return 1;
        return 0;
    }
    return 0;
}