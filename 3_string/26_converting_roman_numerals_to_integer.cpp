/*
    link: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

    logic:
    iterate from the end

    case 1: where the next char is equal or greater then simply add it. eg. MC, XXI
    case 2: where the next char is less than the current char eg. IV, CD etc.
        then here we add the val(current_char)-val(next_char) and parallely iterator++
        to avoid considering the next char.
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N)
    SC: O(1)
*/
int val(char c) {
    if (c == 'M') return 1000;
    if (c == 'D') return 500;
    if (c == 'C') return 100;
    if (c == 'L') return 50;
    if (c == 'X') return 10;
    if (c == 'V') return 5;
    if (c == 'I') return 1;
}
int romanToDecimal(string& s) {
    // code 
    int m = s.size();
    int ans = 0;

    for (int i = m - 1;i >= 0;i--) {
        if (i > 0 && val(s[i - 1]) < val(s[i])) {
            ans += val(s[i]) - val(s[i - 1]);
            i--;
        }
        else {
            ans += val(s[i]);
        }
    }
    return ans;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// similar solution
int val(char c) {
    if (c == 'M') return 1000;
    if (c == 'D') return 500;
    if (c == 'C') return 100;
    if (c == 'L') return 50;
    if (c == 'X') return 10;
    if (c == 'V') return 5;
    if (c == 'I') return 1;
}
int romanToDecimal(string& s) {
    // code 
    int m = s.size();
    int ans = 0;
    int prev = val(s[m - 1]);
    ans += prev;
    for (int i = m - 2;i >= 0;i--) {
        int currVal = val(s[i]);

        if (currVal >= prev) ans += currVal;
        else {
            ans -= currVal;
        }
        prev = currVal;
    }
    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// similar solution
int romanToDecimal(string& str)
{
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        /*If present value is less than next value,
          subtract present from next value and add the
          resultant to the sum variable.*/
        if (m[str[i]] < m[str[i + 1]])
        {
            sum += m[str[i + 1]] - m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}





// ----------------------------------------------------------------------------------------------------------------------- //
// iteration from front to end
int value(char c) {
    if (c == 'M') return 1000;
    if (c == 'D') return 500;
    if (c == 'C') return 100;
    if (c == 'L') return 50;
    if (c == 'X') return 10;
    if (c == 'V') return 5;
    if (c == 'I') return 1;
}

// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
    // Initialize result
    int res = 0;

    // Traverse given input
    for (int i = 0; i < str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i + 1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);

            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else
            {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}