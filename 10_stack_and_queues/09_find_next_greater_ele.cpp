/*
    link: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

    ref: stack_tut/1_next_greater_to_right.cpp
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive method
    TC: O(N^2)
    SC: O(1)
*/
void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " -- "
            << next << endl;
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(N)
    TC: O(N)
*/
vector<long long> nextLargerElement(vector<long long> arr, int n) {
        // Your code here
    stack<long long> s;
    vector<long long> ans(n);

    for (int i = n - 1;i >= 0;i--) {
        while (s.size() && s.top() <= arr[i]) s.pop();

        if (s.size() == 0) {
            ans[i] = -1;
        }
        else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using map and also iterating in the same order of input
    advantage: when there is continuous input we can use this method

    TC: O(N)
    SC: O(N)

*/
void printNGE(int arr[], int n)
{
    stack<int> s;
    unordered_map<int, int> mp;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i = 1; i < n; i++)
    {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
           a) print the pair
           b) keep popping while elements are
           smaller and stack is not empty */
        while (s.empty() == false
            && s.top() < arr[i])
        {
            mp[s.top()] = arr[i];
            s.pop();
        }

        /* push next to stack so that we can find
           next smaller for it */
        s.push(arr[i]);
    }

    /* After iterating over the loop, the remaining
       elements in stack do not have the next smaller
       element, so print -1 for them */
    while (s.empty() == false)
    {
        mp[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ---> "
        << mp[arr[i]] << endl;
}