/*
    link: https://practice.geeksforgeeks.org/problems/minimum-sum4058/1

    sol: https://www.geeksforgeeks.org/minimum-sum-two-numbers-formed-digits-array/
    sol2: https://www.geeksforgeeks.org/minimum-sum-two-numbers-formed-digits-array-2/

    what is c_str ?
    https://www.geeksforgeeks.org/basic_string-c_str-function-in-c-stl/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// accepted 
class Solution {
public:
    // Function for finding sum of larger numbers
    string findSum(string str1, string str2) {
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length()) swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n1 - 1; i >= 0; i--) {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining digits of str2[]
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry) str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }


    string solve(int arr[], int n) {
        // sort the array
        sort(arr, arr + n);

        // let two numbers be a and b
        string a, b;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            // fill a and b with every alternate digit
            // of input array
            if (i & 1)
                a += (char)(arr[i] + '0');
            else
                b += (char)(arr[i] + '0');
        }

        // return the sum
        return findSum(a, b);
    }
};






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using sorting

    TC: O(N logN)
*/
// C++ program to find minimum sum of two numbers
// formed from digits of the array.
#include <bits/stdc++.h>
using namespace std;

// Function to find and return minimum sum of
// two numbers formed from digits of the array.
int solve(int arr[], int n)
{
    // sort the array
    sort(arr, arr + n);

    // let two numbers be a and b
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        // fill a and b with every alternate digit
        // of input array
        if (i & 1)
            a = a * 10 + arr[i];
        else
            b = b * 10 + arr[i];
    }

    // return the sum
    return a + b;
}

// Driver code
int main()
{
    int arr[] = { 6, 8, 4, 5, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum is " << solve(arr, n);
    return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using minHeap
*/
// C++ program to find minimum sum of two numbers
// formed from all digits in a given array.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of two numbers formed
// from all digits in a[]
int minSum(int arr[], int n)
{
    // min Heap
    priority_queue <int, vector<int>, greater<int> > pq;

    // to store the 2 numbers formed by array elements to
    // minimize the required sum
    string num1, num2;

    // Adding elements in Priority Queue
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    // checking if the priority queue is non empty
    while (!pq.empty())
    {
        // appending top of the queue to the string
        num1 += (48 + pq.top());
        pq.pop();
        if (!pq.empty())
        {
            num2 += (48 + pq.top());
            pq.pop();
        }
    }

    // converting string to integer
    int a = atoi(num1.c_str());
    int b = atoi(num2.c_str());

    // returning the sum
    return a + b;
}

int main()
{
    int arr[] = { 6, 8, 4, 5, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSum(arr, n) << endl;
    return 0;
}
