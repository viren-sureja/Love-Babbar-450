/*
    link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    ->  we will push [, {, (, while now if we get ), }, ], and if the top is opposite of the same bracket
        then we pop it as it make balanced.
    -> at last if the size of the stack is 0. then it is balanced neither it is not.

    TC: O(N)
    SC: O(N)
*/
bool ispar(string x)
{
    stack<char> s;
    for (char c : x) {
        if (c == '[' | c == '{' | c == '(') {
            s.push(c);
        }
        else {
            // size is 0 but here we have ending bracket that's not balanced
            if (s.size() == 0) {
                return false;
            }
            else if (c == ']' && s.top() == '[') s.pop();
            else if (c == '}' && s.top() == '{') s.pop();
            else if (c == ')' && s.top() == '(') s.pop();
            else {  // ending bracket is not matching with starting bracket.
                return false;
            }
        }
    }
    // if still there r some starting bracket left then it is not balanced
    return (s.size()) ? false : true;
}



