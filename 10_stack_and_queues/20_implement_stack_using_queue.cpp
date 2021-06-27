/*
    link: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    method 1
    By making pop operation costly
*/

//Function to push an element into stack using two queues.
void QueueStack::push(int x)
{
    // simply push everytime
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack::pop()
{
    // if q1 is empty 
    if (!q1.size()) return -1;

    // get front ele. of q1 till size 1 and store them in q2
    while (q1.size() > 1) {
        int dummy = q1.front();
        q2.push(dummy);
        q1.pop();
    }

    // as end element is ans we have to return .
    int ans = q1.front();

    // emptying q1.
    q1.pop();

    // get all the element in same order again in q1.
    while (q2.size()) {
        int temp = q2.front();
        q2.pop();
        q1.push(temp);
    }
    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    method 2
    By making push operation costly
*/

//Function to push an element into stack using two queues.
void QueueStack::push(int num) {

    //while first queue is not empty, we keep popping the front element
    //from first queue and storing that element in second queue.
    while (!q1.empty())
    {
        int k = q1.front();

        //popping element from first queue.
        q1.pop();

        //pushing it into second queue.
        q2.push(k);
    }

    //q1 is empty now and we push the given number into first queue.
    q1.push(num);

    //while second queue is not empty, we keep popping the front element
    //from second queue and storing that element in first queue.
    while (!q2.empty())
    {
        int k = q2.front();
        //popping element from second queue.
        q2.pop();

        //pushing it into first queue.
        q1.push(k);
    }
}
//Function to pop an element from stack using two queues. 
int QueueStack::pop() {

    //if first queue is not empty, then we can pop an element.
    if (!q1.empty())
    {
        //we store the front element from the queue in a 
        //variable and pop that element.
        int r = q1.front();
        q1.pop();

        //returning the popped element.
        return r;
    }
    //else we return -1.
    return -1;
}