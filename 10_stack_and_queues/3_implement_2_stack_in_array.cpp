/*
    link: https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

    sol: https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
//Function to push an integer into the stack1.
void twoStacks::push1(int x)
{
    if (top1 >= top2 - 1) return;
    arr[++top1] = x;
}

//Function to push an integer into the stack2.
void twoStacks::push2(int x)
{
    if (top2 <= top1 + 1) return;
    arr[--top2] = x;
}

//Function to remove an element from top of the stack1.
int twoStacks::pop1()
{
    if (top1 == -1) return -1;
    int ans = arr[top1--];
    return ans;
}

//Function to remove an element from top of the stack2.
int twoStacks::pop2()
{
    if (top2 == size) return -1;
    int ans = arr[top2++];
    return ans;
}
