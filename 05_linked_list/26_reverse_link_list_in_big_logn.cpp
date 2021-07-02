/*
    https://www.geeksforgeeks.org/can-we-reverse-a-linked-list-in-less-than-on/

    https://www.quora.com/Is-it-possible-to-reverse-a-linked-list-in-less-than-O-n-time

    https://www.tutorialcup.com/interview/linked-list/reverse-linked-list-less-time.htm

    https://tutorialspoint.dev/data-structure/linked-list/can-we-reverse-a-linked-list-in-less-than-on
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    It doesn’t look possible to reverse a simple singly linked list.
    A simple singly linked list can only be reversed in O(n) time using recursive and iterative methods.

    A memory efficient doubly linked list with head and tail pointers can also be reversed in O(1) time
    by swapping head and tail pointers.

    A doubly linked list with head and tail pointers can also be reversed in O(1) time
    by swapping head and tail pointers. But we would have to traverse the list in forward direction
    using prev pointer and reverse direction using next pointer which may not be considered valid.
*/