/*
    link(java): https://www.tutorialspoint.com/javaexamples/data_stack.htm

    link(cpp): https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class MyStack {
    int top;

    public:
    stack() { top = -1; }
    int arr[MAX];


    // method to push the ele. in stack
    void push(int x) {

        // if the current is array is full, then increase the size and assign new address of increased 
        // array in new_arr.
        if (top >= MAX - 1) {
            MAX += MAX;
            int new_arr[MAX];
            for (int i = 0;i <= top;i++) {
                new_arr[i] = arr[i];
            }
            delete(arr);
            arr = new_arr;
        }

        arr[++top] = x;
    }

    // method to pop ele.
    int pop() {
        // if top is less than 0. means stack is empty.
        if (top < 0) {
            cout << "stack underflow" << endl;
            return 0;
        }

        int x = arr[top--];
        return x;
    }

    // method to return top of the stack.
    int top() {
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        }
        else {
            return a[top];
        }
    }

    // method to check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // method to get size of the stack.
    int size() {
        return top + 1;
    }
}
