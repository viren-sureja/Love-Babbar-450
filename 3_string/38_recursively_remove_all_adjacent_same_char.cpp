/*
    link: https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// with iteration
string removeConsecutiveCharacter(string s)
{
    // code here.
    string ans = "";
    int n = s.size();
    int i = 0;
    while (i < n) {
        ans += s[i];
        char temp = s[i];
        while (temp == s[i] && i < n) i++;

    }
    return ans;
}


// ----------------------------------------------------------------------------------------------------------------------- //
// using stack
string removeConsecutiveCharacter(string s)
{
    //only entering those elements in stack which are unique consecutively.
    stack<char> st;
    int n = s.size();
    for (int i = 0;i < n;i++)
    {
        if ((st.empty() == 0 && st.top() != s[i]) || st.empty() == 1)
            st.push(s[i]);
    }
    // storing stack elements in string.	
    string res;
    while (st.empty() == 0)
    {
        res += st.top();
        st.pop();
    }
    // reversing the string because stack is a LIFO data structure.	
    reverse(res.begin(), res.end());
    return res;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// with recursion
void removeDuplicates(char* S)
{
    // When string is empty, return
    if (S[0] == '\0')
        return;

    // if the adjacent characters are same
    if (S[0] == S[1]) {

        // Shift character by one to left
        int i = 0;
        while (S[i] != '\0') {
            S[i] = S[i + 1];
            i++;
        }

        // Check on Updated String S
        removeDuplicates(S);
    }

    // If the adjacent characters are not same
    // Check from S+1 string address
    removeDuplicates(S + 1);
}
