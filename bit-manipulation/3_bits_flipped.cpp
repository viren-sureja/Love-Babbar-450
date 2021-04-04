/*

link: https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

to find set bits: __builtin_popcount(N);
// or
int count = 0;
while(n) {
    count += n & 1;
    n = n>>1;
}

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// method 1 (naive)
int countBitsFlip(int a, int b) {
    int count = 0;
    // as int can be max of 32 bit.
    for (int i = 0;i < 32;i++) {
        // checking every bit
        if ((a & (1 << i)) ^ (b & (1 << i))) count++;
    }
    return count;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 2
int countBitsFlip(int a, int b) {
    // will set 1 when both bit are different 
    int a_xor_b = a ^ b;

    return __builtin_popcount(a_xor_b);
}

// ----------------------------------------------------------------------------------------------------------------------- //