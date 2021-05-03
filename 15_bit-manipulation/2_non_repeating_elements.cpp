/*

    link: https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
    sol: https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
    video: https://www.youtube.com/watch?v=pnx5JA9LNM4


    to find the least set bit :     a & ~(a - 1);
    alternative:
        int i = 0;
        int a = 1;
        while (true) {
            a = 1 << i;
            if (main_xor & (1 << i++)) break;
        }
*/

// ----------------------------------------------------------------------------------------------------------------------- //

vector<int> singleNumber(vector<int> nums)
{
    // let's assume x and y be different without pair
    int main_xor = nums[0];
    for (int i = 1;i < nums.size();i++) {
        main_xor ^= nums[i];
    }
    // now in main_xor we have x^y as all other will be pair, by doing xor will cut each other and will be 0.

    /* here is the crux: here if we see the bits in main_xor which are set are the one different in both x and y
        thus if we again xor the array on basis of bit(choose any set bit from main_xor, least bit will be fine)
        and thus as x and y have different bits on this selected set bit and thus now both x and y will be diff.
        by ANDing as below.
     */

    // to get least bit from main_xor
    int least = main_xor & (~(main_xor - 1));

    // separating the x and y.
    int x = 0, y = 0;
    for (auto i : nums) {
        if (i & least) x ^= i;
        else y ^= i;
    }

    if (x < y) return { x,y };
    else return { y, x };
}

// ----------------------------------------------------------------------------------------------------------------------- //