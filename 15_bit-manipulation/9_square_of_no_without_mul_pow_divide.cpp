/*
    link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/#:~:text=Given%20an%20integer%20n%2C%20calculate,*%2C%20%2F%20and%20pow().&text=A%20Simple%20Solution%20is%20to%20repeatedly%20add%20n%20to%20result.
    sol: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/#:~:text=Given%20an%20integer%20n%2C%20calculate,*%2C%20%2F%20and%20pow().&text=A%20Simple%20Solution%20is%20to%20repeatedly%20add%20n%20to%20result.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// naive method
int without_MPD(int n) {
    n = abs(n);
    for (int i = 0;i < n;i++) {
        n += n;
    }
    return n;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// approach 2
// TC: O(log N) 
int without_MPD(int n) {
    n = abs(n);
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2) {
        return ((without_MPD(n / 2) << 2) + ((n / 2) << 2) + 1);
    }
    else {
        return (without_MPD(n / 2) << 2);
    }
}

// ----------------------------------------------------------------------------------------------------------------------- //

// approach 3
// TC: O(log N)
int without_MPD(int n) {
    n = abs(n);
    int ans = n;
    for (int i = 0;i < 32;i++) {
        int temp = (1 << i);
        if (temp & n) {
            ans += (n << i);
        }
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //