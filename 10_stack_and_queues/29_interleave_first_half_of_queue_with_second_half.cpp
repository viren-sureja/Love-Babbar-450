/*
    link: https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(n/2) => O(N)
    SC: O(N/2) => O(N)
*/
// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;

    // Initialize an empty stack of int type
    stack<int> s;
    int halfSize;
    if (q.size() % 2)  halfSize = q.size() / 2 + 1;
    else halfSize = q.size() / 2;

    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using another queue

*/
// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0) cout << "Input even number of integers." << endl;

    // Initialize an empty stack of int type
    queue<int> qDummy;
    int halfSize;
    if (q.size() % 2)  halfSize = q.size() / 2 + 1;
    else halfSize = q.size() / 2;

    // Push first half elements into the dummy queue
    for (int i = 0; i < halfSize; i++) {
        qDummy.push(q.front());
        q.pop();
    }


    // interleave the elements of queue and dummy queue
    while (!qDummy.empty()) {
        // take one ele. from dummy queue
        q.push(qDummy.front());
        qDummy.pop();

        // take another from main queue
        q.push(q.front());
        q.pop();
    }
}