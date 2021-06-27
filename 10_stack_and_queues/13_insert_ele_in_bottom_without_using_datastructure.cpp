/*
    link: https://stackoverflow.com/questions/45130465/inserting-at-the-end-of-stack
*/


// ----------------------------------------------------------------------------------------------------------------------- //
static void insert_at_bottom(char x) {

    if (st.isEmpty())
        st.push(x);

    else {
        /* All items are held in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the st.size() becomes 0, the
           above if part is executed and the item is inserted
           at the bottom */

        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
}