/*
    link: https://practice.geeksforgeeks.org/problems/queue-reversal/1

    sol(recursion): https://www.geeksforgeeks.org/reversing-queue-using-recursion/
    sol(stack): https://www.geeksforgeeks.org/reversing-a-queue/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
    TC: O(N)
    SC: O(1)
*/
void reverse(queue<int>& q) {

    // if queue is empty return it as it is.
    if (q.empty()) return;

    // get front element and pop it.
    int x = q.front();
    q.pop();

    // recursively call all the element (at last all ele. will be in call stack and then start inserting all ele.)
    reverse(q);

    // hence this time enqueueing ele. will get in reverse order.
    q.push(x);
}
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(N)
    SC: O(N)
*/
queue<int> rev(queue<int> q)
{
    stack<int> s;

    // push all ele. in stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // in stack all ele. gets arrange in reverse order

    // using LIFO we will pop out all the ele. and push into the queue.
    while (s.size()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}