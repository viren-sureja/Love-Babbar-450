/*
    link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

    sol: https://www.geeksforgeeks.org/factorial-large-number/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
class Solution {
public:
    // this function takes k to multiply with array (array here is whole digit with first digit at 0th of array)
    int mul(vector<int>& arr, int k, int size) {
        int carry = 0;
        for (int i = 0;i < size;i++) {
            int curr_mul = k * arr[i] + carry;
            arr[i] = curr_mul % 10;
            carry = curr_mul / 10;
        }
        // if carry is not zero then we have to push_back at the end.
        while (carry) {
            arr.push_back(carry % 10);
            carry /= 10;
            size++;
        }
        return size;
    }
    vector<int> factorial(int n) {
        // code here
        vector<int> arr = { 1 };
        int size = 1;
        for (int i = 2;i <= n;i++) {
            // updating size and array everytime
            size = mul(arr, i, size);
        }

        // we have first digit at 0th place hence we have to reverse
        // eg. for 5 it will be {0, 2, 1} => {1, 2, 0}
        reverse(arr.begin(), arr.end());
        return arr;
    }
};




// ----------------------------------------------------------------------------------------------------------------------- //
// alternate solution
#define MAX 1000
string factorial(long long n)
{
    if (n > MAX) {
        cout << " Integer Overflow"
            << endl;
        return "";
    }

    long long counter;
    long double sum = 0;

    // Base case
    if (n == 0)
        return "1";

    // Calculate the sum of logarithmic values
    for (counter = 1; counter <= n;
        counter++) {
        sum = sum + log(counter);
    }

    // Number becomes too big to hold in unsigned long integers. Hence converted to string
    // Answer is sometimes under estimated due to floating point operations so round() is used
    string result = to_string(round(exp(sum)));
    // here exp is calculated bcoz: log(n!) = sum = log(1) + .... log(n), now n! = e^sum.
    return result;
}