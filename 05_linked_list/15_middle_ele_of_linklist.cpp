/*
    link: https://leetcode.com/problems/middle-of-the-linked-list/submissions/


    case 1: fast->next will be NULL
            1->2->3->4->5       when fast->next will be NULL slow will be at 3.

    case 2: fast->next->next will be NULL
            1->2->3->4->5->6    when fast->next->next will be NULL slow will be at 4.


*/


// ----------------------------------------------------------------------------------------------------------------------- //
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next) {
        // slow pointer jumps 1 at a time
        slow = slow->next;

        if (fast->next->next == NULL) break;

        // fast pointer jumps 2 at a time
        fast = fast->next->next;
    }
    return slow;
}