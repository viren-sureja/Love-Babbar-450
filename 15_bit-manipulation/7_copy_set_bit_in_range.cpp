/*
    link: https://www.geeksforgeeks.org/copy-set-bits-in-a-range/
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// here in bit range check if is there any 1 in y then update x if x has 0 at that pos.
// TC: O(r-l) or O(const.) hence O(1) as r and l will be in range of 32.
int newNum(int x, int y, int l, int r) {
    for (int i = l;i <= r;i++) {
        int temp = 1 << i - 1;
        if (temp & y) {
            if (temp & x) continue;
            else x |= temp;
        }
    }
    return x;
}

// ----------------------------------------------------------------------------------------------------------------------- //