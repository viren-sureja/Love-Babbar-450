/*
    link: https://www.geeksforgeeks.org/next-smaller-element/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive method
    TC: O(N^2)
    SC: O(1)
*/
/* prints element and NSE pair
for all elements of arr[] of size n */
void printNSE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
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
    using stack (simpler way && outputs same as input)
    TC: O(N)
    SC: O(N)
*/
void printNSE(int arr[], int n) {

    stack<int> s;
    vector<int> v;

    for (int i = n - 1;i >= 0;i++) {
        int ans;
        while (!s.size() && s.top() > arr[i]) s.pop();

        if (s.size()) ans = s.top();
        else ans = -1;

        s.push(arr[i]);
        v.push_back(ans);
    }
    reverse(v.begin(), v.end());

    for (int i : v) cout << i << " ";
    cout << endl;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    getting output in same order as input. [will only works for unique elements]

    using hashmap
*/
/* prints element and NSE pair for all
elements of arr[] of size n */
void printNSE(int arr[], int n)
{
    stack<int> s;
    unordered_map<int, int> mp;

    /* push the first element to stack */
    s.push(arr[0]);


    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {

        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then
       pop an element from stack.
       If the popped element is greater
       than next, then
    a) print the pair
    b) keep popping while elements are
    greater and stack is not empty */
        while (s.empty() == false && s.top() > arr[i]) {
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
    while (s.empty() == false) {
        mp[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ---> " << mp[arr[i]] << endl;
}
