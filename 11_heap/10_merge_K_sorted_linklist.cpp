/*
    link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

    also refer: linked_list/31_merge_k_sorted_LL
*/

// ----------------------------------------------------------------------------------------------------------------------- //
// using heap
typedef pair<int, Node*> pin;

class Solution {
public:

    Node* mergeKLists(Node* arr[], int k)
    {
        // minHeap to get min. ele of all K sorted LL
        priority_queue <pin, vector<pin>, greater<pin>> pq;

        for (int i = 0;i < k;i++) {
            pq.push({ arr[i]->data, arr[i] });
        }

        Node* ans = new Node(0);
        Node* finalAns = ans;

        while (!pq.empty()) {
            pin curr = pq.top();
            pq.pop();

            // append the curr's address in ans LL
            ans->next = curr.second;
            ans = ans->next;

            // if next of curr exist then append it.
            if ((curr.second)->next != NULL) pq.push({ (curr.second)->next->data, (curr.second)->next });
        }

        return finalAns->next;
    }
};