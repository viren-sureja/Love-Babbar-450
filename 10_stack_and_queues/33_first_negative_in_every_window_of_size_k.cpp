/*
    link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

    sol: https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive algo.   (for every element iterate window size and find first negative)
    TC: O((n-k+1)*k) => O(n*k)
    SC: O(1)
*/
void printFirstNegativeInteger(int arr[], int n, int k)
{
    // flag to check whether window contains
    // a negative integer or not
    bool flag;

    // Loop for each subarray(window) of size k
    for (int i = 0; i < (n - k + 1); i++)
    {
        flag = false;

        // traverse through the current window
        for (int j = 0; j < k; j++)
        {
            // if a negative integer is found, then
            // it is the first negative integer for
            // current window. Print it, set the flag
            // and break
            if (arr[i + j] < 0)
            {
                cout << arr[i + j] << " ";
                flag = true;
                break;
            }
        }

        // if the current window does not
        // contain a negative integer
        if (!flag)
            cout << "0" << " ";
    }
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue
    TC: O(N)
    SC: O(N)
*/
vector<ll> printFirstNegativeInteger(lli A[], lli N, lli K) {
    vector<ll> ans;
    queue<lli> q;

    // push all the negative integer.
    for (lli i = 0;i < N;i++) {
        if (A[i] < 0) q.push(i);
    }

    // for every pos.
    for (lli i = 0;i < N - K + 1;i++) {

        // if queue is empty means no negative no. in upcoming so push 0.
        if (!q.size()) ans.push_back(0);
        // front of queue is current pos so pop.
        else if (q.front() == i) {
            ans.push_back(A[i]);
            q.pop();
        }
        // check if the negative pos. in front of queue lies in window size.
        else {
            if (q.front() <= min(i + K - 1, N)) {
                ans.push_back(A[q.front()]);
            }
            else {
                ans.push_back(0);
            }
        }
    }
    return ans;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    optimization of above
    TC: O(N-K+1) => O(N)
    SC: O(K)
*/
vector<ll> printFirstNegativeInteger(lli A[], lli N, lli K) {
    vector<ll> ans;
    queue<lli> q;

    // as compare to above use only K size of queue.
    for (lli i = 0;i < K;i++) {
        if (A[i] < 0) q.push(i);
    }

    for (lli i = 0;i < N - K + 1;i++) {
        // if queue is empty than push 0, neither negative ele. in window exist
        if (q.empty()) ans.push_back(0);
        else ans.push_back(A[q.front()]);

        // remove all pos from queue which are out of window range
        if (q.size() && q.front() <= i) q.pop();

        // check if the i+K th ele. is negative and then we push, for our next evaluation.
        if (i + K <= N - 1 && A[i + K] < 0) q.push(i + K);
    }
    return ans;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using dequeue
    TC: O(N)
    SC: O(K)
*/
void printFirstNegativeInteger(int arr[], int n, int k)
{
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<int>  Di;

    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++)
    {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
            cout << arr[Di.front()] << " ";

        // else the window does not have a
        // negative integer
        else
            cout << "0" << " ";

        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front();  // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
        cout << arr[Di.front()] << " ";
    else
        cout << "0" << " ";

}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    most optimized solution
    TC: O(N)
    SC: O(1)
*/
void printFirstNegativeInteger(int arr[], int k, int n)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;


    for (int i = k - 1; i < n; i++)
    {

        // skip out of window and positive elements
        while ((firstNegativeIndex < i) &&
            (firstNegativeIndex <= i - k ||
                arr[firstNegativeIndex] > 0))
        {
            firstNegativeIndex++;
        }

        // check if a negative element is found, otherwise use 0
        if (arr[firstNegativeIndex] < 0)
        {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else
        {
            firstNegativeElement = 0;
        }
        cout << firstNegativeElement << " ";
    }

}
