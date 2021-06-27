/*
    link:   https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

    ref: 3_string/16_balanced_paranthesis.cpp
*/


// ----------------------------------------------------------------------------------------------------------------------- //
bool ispar(string x)
{
    stack<char> s;
    for (char c : x) {
        if (c == '[' | c == '{' | c == '(') {
            s.push(c);
        }
        else {
            if (s.size() == 0) {
                return false;
            }
            else if (c == ']' && s.top() == '[') s.pop();
            else if (c == '}' && s.top() == '{') s.pop();
            else if (c == ')' && s.top() == '(') s.pop();
            else {
                return false;
            }
        }
    }
    return (s.size()) ? false : true;
}