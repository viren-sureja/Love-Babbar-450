/*
    link (for postfix): https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

    sol (for prefix): https://www.geeksforgeeks.org/evaluation-prefix-expressions/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    evaluation of postfix expression
*/

// function to evaluate expression w.r.t. sign.
int evaluate(int an, int bn, char opr) {
    int ans = 0;

    if (opr == '*') {
        ans = an * bn;
    }
    else if (opr == '/') {
        ans = an / bn;
    }
    else if (opr == '+') {
        ans = an + bn;
    }
    else if (opr == '-') {
        ans = an - bn;
    }
    else if (opr == '^') {
        ans = an ^ bn;
    }
    return ans;
}

//Function to evaluate a postfix expression.
int evaluatePostfix(string S)
{
    stack<int> st;
    int n = S.size();

    for (int i = 0;i < n;i++) {
        // if its digit just push it.
        if (isdigit(S[i])) {
            st.push(S[i] - '0');
        }
        // if operator pop first 2 ele and evaluate and push ans.
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            st.push(evaluate(a, b, S[i]));

        }
    }

    // finally the top will the ans.
    return st.top();
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    evaluation of prefix expression
*/
// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    // If the character is a digit then it must
    // be an operand
    return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
    stack<double> Stack;

    // in prefix we start from the end to avoid reversing the string.
    for (int j = exprsn.size() - 1; j >= 0; j--) {

        // Push operand to Stack
        // To convert exprsn[j] to digit subtract
        // '0' from exprsn[j].
        if (isOperand(exprsn[j]))
            Stack.push(exprsn[j] - '0');

        else {

            // Operator encountered
            // Pop two elements from Stack
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            // Use switch case to operate on o1
            // and o2 and perform o1 O o2.
            switch (exprsn[j]) {
                case '+':
                    Stack.push(o1 + o2);
                    break;
                case '-':
                    Stack.push(o1 - o2);
                    break;
                case '*':
                    Stack.push(o1 * o2);
                    break;
                case '/':
                    Stack.push(o1 / o2);
                    break;
            }
        }
    }

    return Stack.top();
}

// Driver code
int main()
{
    string exprsn = "+9*26";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;
}
