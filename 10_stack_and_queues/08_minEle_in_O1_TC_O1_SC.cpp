/*
    link: https://practice.geeksforgeeks.org/problems/special-stack/1

    ref: stack_tut/10_min_ele....
*/



// ----------------------------------------------------------------------------------------------------------------------- //
int min_ele;
void push(stack<int>& s, int a) {
    // Your code goes here
    if (s.size() == 0) {
        s.push(a);
        min_ele = a;
    }
    else {
        if (a < min_ele) {
            s.push(2 * a - min_ele);
            min_ele = a;
        }
        else {
            s.push(a);
        }
    }
}

bool isFull(stack<int>& s, int n) {
    // Your code goes here
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    // Your code goes here
    return s.size() == 0;
}

int pop(stack<int>& s) {
    // Your code goes here
    if (s.top() < min_ele) {
        int ans = min_ele;
        min_ele = 2 * min_ele - s.top();
        s.pop();
    }
    else {
        s.pop();
    }
}

int getMin(stack<int>& s) {
    // Your code goes here
    return min_ele;
}