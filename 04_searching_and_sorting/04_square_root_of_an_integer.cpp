/*
    link: https://practice.geeksforgeeks.org/problems/count-squares3649/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    note: said "less than N"
    TC: O(1)
*/
int countSquares(int N) {

    int ans = sqrt(N - 1);

    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(sqrt(n-1))
*/
int countSquares(int N) {
        // code here
    int i = 1, count = 0;
    while ((i * i) < N) i++;
    return i - 1;
}
