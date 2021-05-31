/*
    link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

    sol(queue): https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/

    sol(DLL): https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using iteration
*/
string FirstNonRepeating(string A) {
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    string ans = "";

    int n = A.size();

    // it will show the prev farthest pos whose occurence is 1.
    int last_single = 0;
    // prev farthest pos char.
    char single_char = A[last_single];

    for (int i = 0;i < n;i++) {
        // increase the occurence of each char.
        cnt[A[i] - 'a']++;

        // if count of current char is >1
        if (cnt[single_char - 'a'] != 1)
        {
            // incase if we wont be able to find such char whose occurence is 1.
            single_char = '#';

            // finds prev farthest char whose occurence is once.
            while (last_single <= i) {
                if (cnt[A[last_single] - 'a'] == 1) {
                    single_char = A[last_single];
                    break;
                }
                last_single++;
            }
        }
        ans += single_char;
    }

    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue
*/
string firstnonrepeating(char str[])
{
    string ans = "";
    queue<char> q;
    char curr = '#';
    int charCount[26] = { 0 };

    // traverse whole stream
    for (int i = 0; str[i]; i++) {

        // push each character in queue
        q.push(str[i]);

        // increment the frequency count
        charCount[str[i] - 'a']++;

        // check for the non pepeating character
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1) {
                q.pop();
            }
            else {
                curr = q.front();
                break;
            }
        }

        if (q.empty()) curr = '#';
        ans += curr;
    }

    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using DLL
*/

// A utility function to append a character x at the end
// of DLL. Note that the function may change head and tail
// pointers, that is why pointers to these pointers are
// passed.
void appendNode(struct node** head_ref,
    struct node** tail_ref, char x)
{
    struct node* temp = new node;
    temp->a = x;
    temp->prev = temp->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}

// A utility function to remove a node 'temp' fromt DLL.
// Note that the function may change head and tail pointers,
// that is why pointers to these pointers are passed.
void removeNode(struct node** head_ref,
    struct node** tail_ref, struct node* temp)
{
    if (*head_ref == NULL) return;

    if (*head_ref == temp) *head_ref = (*head_ref)->next;
    if (*tail_ref == temp) *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;

    delete (temp);
}

void findFirstNonRepeating()
{
    // inDLL[x] contains pointer to
    // a DLL node if x is present
    // in DLL. If x is not present, then inDLL[x] is NULL
    struct node* inDLL[26];

    // repeated[x] is true if x is repeated two or more
    // times. If x is not seen so far or x is seen only
    // once. then repeated[x] is false
    bool repeated[26];

    // Initialize the above two arrays
    struct node* head = NULL, * tail = NULL;
    for (int i = 0; i < 26; i++) {
        inDLL[i] = NULL;
        repeated[i] = false;
    }

    // Let us consider following stream and see the process
    char stream[] = "geeksforgeeksandgeeksquizfor";
    for (int i = 0; stream[i]; i++) {
        char x = stream[i];
        cout << "Reading " << x << " from stream \n";

        // We process this character only if it has not
        // occurred or occurred only once. repeated[x] is
        // true if x is repeated twice or more.s
        if (!repeated[x]) {
            // If the character is not in DLL, then add this
            // at the end of DLL.
            if (inDLL[x] == NULL) {
                appendNode(&head, &tail, stream[i]);
                inDLL[x] = tail;
            }
            else // Otherwise remove this character from DLL
            {
                removeNode(&head, &tail, inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true; // Also mark it as repeated
            }
        }

        // Print the current first non-repeating character from stream
        if (head != NULL) ans += (head->a);
        else ans += '#';
    }
}
