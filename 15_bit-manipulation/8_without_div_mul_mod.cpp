/*
    link: https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
    video: https://www.youtube.com/watch?v=bdxJHWIyyqI
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(a)
int without_DMM(int dividend, int divisor) {
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }
    return quotient * sign;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// TC: O(log(a))
int without_DMM(int dividend, int divisor) {
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int quotient = 0;
    int temp = 0;
    for (int i = 31;i >= 0;i--) {
        // Add the result in temp variable for checking the next position such that (temp + (divisor << i) ) is less than dividend.
        if (temp + (divisor << 1) <= dividend) {
            temp += divisor << 1;
            quotient |= 1 << i;
        }
    }

    return quotient * sign;
}

// ----------------------------------------------------------------------------------------------------------------------- //