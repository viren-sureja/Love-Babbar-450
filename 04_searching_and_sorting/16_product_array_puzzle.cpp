/*
    link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

    sol: https://www.geeksforgeeks.org/a-product-array-puzzle/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    with count of 0
*/
vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {

    lli prod = 1;
    vector<lli> ans;
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        if (arr[i] != 0) prod *= arr[i];
        else cnt++;
    }
    if (cnt >= 2) {
        for (int i = 0;i < n;i++) {
            ans.push_back(0);
        }
    }
    else if (cnt == 1) {
        for (int i = 0;i < n;i++) {
            if (arr[i] == 0) ans.push_back(prod);
            else ans.push_back(0);
        }
    }
    else {
        for (int i = 0;i < n;i++) {
            ans.push_back(prod / arr[i]);
        }
    }

    return ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    product from both side.
*/
vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
{
    // Allocate memory for product array andinitialise it by 1
    vector<long long int> vec(n, 1ll);
    if (n == 1)
    {
        return vec;
    }

    // In this loop temp will store the product of values on the left side of nums[i]
    long long temp = 1ll;
    for (int i = 0;i < n;i++)
    {
        vec[i] *= temp;
        temp *= nums[i];
    }

    // In this loop temp will store the product of values on the right side of nums[i]
    temp = 1ll;
    for (int i = n - 1;i >= 0;i--)
    {
        vec[i] *= temp;
        temp *= nums[i];
    }


    return vec; // return the expected vector
}