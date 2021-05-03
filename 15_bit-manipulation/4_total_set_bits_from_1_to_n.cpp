/*

link: https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
sol: https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
video: https://www.youtube.com/watch?v=g6OxU-hRGtY

to find set bits: __builtin_popcount(N);

*/

// ----------------------------------------------------------------------------------------------------------------------- //

int total_popcount(int n) {
    int count = 0;
    while (n) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 1
// TC: O(N)
int countSetBits(int n)
{
    int count = 0;
    for (int i = 1;i <= n;i++) {
        count += total_popcount(i);
    }
    return count;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 2
// TC: O(N log N);
int countSetBits(int n) {
    int i = 0;  // for bit position from least to most significant

    int ans = 0;

    while ((1 << i) <= n) {
        bool k = 0; // temp bit status, will change after certain pos
        int change = 1 << i;
        /* for eg. if bit pos is 0 then it will change alternative and if bit pos is 1 then will change after every 2 occurences. */

        for (int j = 0;j <= n;j++) {
            ans += k;   // save temp bit to ans
            if (change == 1) {
                k = !k;
                change = 1 << i;
            }
            else {
                change--;
            }
        }
        i++;
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// method 3 most optimal
// TC: O(log(N))
// refer: onenote for 
int findPower(int n) {
    int count = 0;
    while ((1 << count) <= n) {
        count++;
    }
    return count - 1;
}
int countSetBits(int n)
{
    if (n == 0) {
        return 0;
    }

    int max_pow_of_2 = findPower(n); // or can use log2(n) instead of self made function.
    int till_pow_of_2 = max_pow_of_2 * (1 << (max_pow_of_2 - 1));

    int extra_line_of_bit = n - (1 << max_pow_of_2) + 1;

    return till_pow_of_2 + extra_line_of_bit + countSetBits(n - (1 << max_pow_of_2));
}

// ----------------------------------------------------------------------------------------------------------------------- //