/*
    link: https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1

    sol: https://www.geeksforgeeks.org/multiply-two-numbers-represented-linked-lists/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
long long multiplyTwoLists(Node* first, Node* second)
{
    long long N = 1e9 + 7;
    long long num1 = 0, num2 = 0;
    while (first || second) {

        if (first) {
            num1 = ((num1) * 10) % N + first->data;
            first = first->next;
        }

        if (second)
        {
            num2 = ((num2) * 10) % N + second->data;
            second = second->next;
        }

    }
    return ((num1 % N) * (num2 % N)) % N;
}