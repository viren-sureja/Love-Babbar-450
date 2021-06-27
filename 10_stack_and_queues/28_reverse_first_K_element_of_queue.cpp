/*
    link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(N + K)
    SC: O(K)
*/
queue<int> modifyQueue(queue<int> q, int k)
{
    /*
        queue: 1 2 3 4 5
        stack:
    */
    int n = q.size();
    stack<int> s;

    // push first k ele. in stack
    for (int i = 0;i < k;i++) {
        s.push(q.front());
        q.pop();
    }

    /*
        queue: 4 5
        stack: 3 2 1
    */
    // now pop from stack and push in queue (as stack reverses the ele.)
    for (int i = 0;i < k;i++) {
        q.push(s.top());
        s.pop();
    }

    /*
        queue: 4 5 3 2 1
        stack:
    */
    // now the reverse ele. will be at last in queue, so pop front (n-k) ele and again push it in queue.
    for (int i = 0;i < n - k;i++) {
        int x = q.front();
        q.pop();
        q.push(x);
    }

    /*
        queue: 3 2 1 4 5
        stack:
    */
    return q;
}