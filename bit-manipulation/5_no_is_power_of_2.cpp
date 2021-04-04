/*
    link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// method 1 (naive method) ( :) not for corporate use)
bool isPowerofTwo(long long n) {
    if (n == 0) return false;
    long double power = log2(n);
    if (floor(power) == power) return true;
    else return false;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 2
// TC: O(log N)
// crux: if there is only 1 set bit then and then only it will be power of 2. try diff. combo as well but will not work.
long long countSetBit(long long n) {
    long long count = 0;
    while (n) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}
bool isPowerofTwo(long long n) {
    if (countSetBit(n) == 1LL) return true;
    return false;
}

// ----------------------------------------------------------------------------------------------------------------------- //