/*
    link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1

    sol: https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void sortedInsert(stack<int>& s, int a) {
    // if stack is empty or top element is smaller than a just push it.
    if (!s.size() || s.top() < a) {
        s.push(a);
    }
    else {
        int temp = s.top();
        s.pop();

        // else pop the top element and call again sortedInsert
        // as top element is larger or equal to current ele.
        sortedInsert(s, a);

        // after sorting push that poped elem which was **larger or equal**
        s.push(temp);
    }
}

void SortedStack::sort()
{
    if (s.size()) {
        int temp = s.top();
        s.pop();

        // calling this function till last element.
        sort();

        // starting to insert from last element.
        sortedInsert(s, temp);
    }
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using another stack
*/

// This function return the sorted stack
stack<int> sortStack(stack<int>& input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        // pop out the first element
        int tmp = input.top();
        input.pop();

        // while temporary stack is not empty and top
        // of stack is greater than temp
        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            // pop from temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // push temp in tempory of stack
        tmpStack.push(tmp);
    }

    return tmpStack;
}

// main function
int main()
{
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    // This is the temporary stack
    stack<int> tmpStack = sortStack(input);
    cout << "Sorted numbers are:\n";

    while (!tmpStack.empty())
    {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }
}
