/*
    link: https://www.geeksforgeeks.org/arithmetic-expression-evalution/#:~:text=The%20stack%20organization%20is%20very,i.e.%2C%20A%20%2B%20B).

    infix notation:  A + B
    Polish notation (prefix notation): +AB
    Reverse Polish notation (postfix notation): AB+

    There are 3 levels of precedence for 5 binary operators as given below:
        Highest: Exponentiation (^)
        Next highest: Multiplication (*) and division (/)
        Lowest: Addition (+) and Subtraction (-)
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    infix to prefix
*/

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {

        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');

        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }

            // Remove '(' from the stack
            char_stack.pop();
        }

        // Operator found
        else
        {
            if (isOperator(char_stack.top()))
            {
                if (infix[i] == '^')
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top()))      // main logic 1 (pop operator if they are same or more prioritized)
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }

                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top()))   // main logic 2 (pop operator if they are more prioritized)
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }

                }

                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}

string infixToPrefix(string infix)
{
    /* Reverse String
    * Replace ( with ) and vice versa
    * Get Postfix
    * Reverse Postfix * */
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

// Driver code
int main()
{
    string s = ("x+y*z/w+u");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}










// ----------------------------------------------------------------------------------------------------------------------- //
/*
    infix to postfix
*/

//Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

    stack<char> st; //For stack operations, we are using C++ built in stack
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.pop();
        }

        //If an operator is scanned
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {            // main logic (pop operator if they are same or more prioritized)
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        char temp = st.top();
        st.pop();
        result += temp;
    }

    cout << result << endl;
}

//Driver program to test above functions
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    prefix to infix
*/
// C++ Program to convert prefix to Infix
#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

// Convert prefix to Infix expression
string preToInfix(string pre_exp) {
    stack<string> s;

    // length of expression
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--) {

        // check if symbol is operator
        if (isOperator(pre_exp[i])) {

        // pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // concat the operands and operator
            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            // Push string temp back to stack
            s.push(temp);
        }

        // if symbol is an operand
        else {

        // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }

    // Stack now contains the Infix expression
    return s.top();
}

// Driver Code
int main() {
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << preToInfix(pre_exp);
    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    postfix to infix
*/
// CPP program to find infix for
// a given postfix.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
        (x >= 'A' && x <= 'Z');
}

// Get Infix for a given postfix
// expression
string getInfix(string exp)
{
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        // Push operands
        if (isOperand(exp[i]))
        {
            string op(1, exp[i]);
            s.push(op);
        }

        // We assume that input is
        // a valid postfix and expect
        // an operator.
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                op1 + ")");
        }
    }

    // There must be a single element
    // in stack now which is the required
    // infix.
    return s.top();
}

// Driver code
int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);
    return 0;
}










// ----------------------------------------------------------------------------------------------------------------------- //
/*
    prefix to postfix
*/
// CPP Program to convert prefix to postfix
#include <iostream>
#include <stack>
using namespace std;

// funtion to check if character is operator or not
bool isOperator(char x)
{
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

    stack<string> s;
    // length of expression
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--)
    {
        // check if symbol is operator
        if (isOperator(pre_exp[i]))
        {
            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // concat the operands and operator
            string temp = op1 + op2 + pre_exp[i];

            // Push string temp back to stack
            s.push(temp);
        }

        // if symbol is an operand
        else {

            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }

    // stack contains only the Postfix expression
    return s.top();
}

// Driver Code
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    postfix to prefix
*/
// CPP Program to convert postfix to prefix
#include <bits/stdc++.h>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x)
{
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

// Convert postfix to Prefix expression
string postToPre(string post_exp)
{
    stack<string> s;

    // length of expression
    int length = post_exp.size();

    // reading from right to left
    for (int i = 0; i < length; i++) {

        // check if symbol is operator
        if (isOperator(post_exp[i])) {

            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // concat the operands and operator
            string temp = post_exp[i] + op2 + op1;

            // Push string temp back to stack
            s.push(temp);
        }

        // if symbol is an operand
        else {

            // push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }

    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}

// Driver Code
int main()
{
    string post_exp = "ABC/-AK/L-*";

    // Function call
    cout << "Prefix : " << postToPre(post_exp);
    return 0;
}
