/*
    link: https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

    sol: https://www.geeksforgeeks.org/queue-using-stacks/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    By making enQueue operation costly
    Time Complexity:
        Push operation: O(N).
            In the worst case we have empty whole of stack 1 into stack 2.
        Pop operation: O(1).
            Same as pop operation in stack.
    Auxiliary Space: O(N).
        Use of stack for storing values.
*/

#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    By making deQueue operation costly
    Time Complexity:
        Push operation: O(1).
            Same as pop operation in stack.
        Pop operation: O(N).
            In the worst case we have empty whole of stack 1 into stack 2
    Auxiliary Space: O(N).
        Use of stack for storing values.
*/

#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // if s2 is empty, move
        // elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using Function Call Stack
    Time Complexity:
        Push operation : O(1).
            Same as pop operation in stack.
        Pop operation : O(N).
            The difference from above method is that in this method element is returned and all elements are restored back in a single call.
    Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;

        // recursive call
        int item = deQueue();

        // push popped item back to the stack
        s.push(x);

        // return the result of deQueue() call
        return item;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}
