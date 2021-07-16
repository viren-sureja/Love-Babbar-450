/*
    sol: https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/

    link: https://leetcode.com/problems/permutation-sequence/

    video: https://youtu.be/wT7gcXLYoao
    (watch the explanation)
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    recursive solution

    TC: O(N!) + O(N logN)  => O(N!)
        N! to generate every combination
        N logN to sort all the permutation

    SC: O(N)  => as we keep deep copy of every combination
*/

set<string> finalAns;
void permute(string s, string answer)
{
    if (s.length() == 0)
    {
        // cout << answer << endl;
        finalAns.insert(answer);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permute(rest, answer + ch);
    }
}
string getPermutation(int n, int k) {
    string str = "";
    for (int i = 1; i <= n; i++) {
        str += i + '0';
    }

    permute(str, "");

    int i = 0;

    for (auto curr : finalAns) {
        i++;
        if (i == k) return curr;
    }
    return "";
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    efficient solution

    TC: O(N * N)  => 1st for iterating to all no. and 2nd for erasing each time in each itertation
    SC: O(N)    => for storing all no.
*/
class Solution {
    public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1;i < n;i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";

        k = k - 1;  // as we will doing operation on 0th based indexing

        while (true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            // IMP
            if (numbers.size() == 0) {
                break;
            }

            // as we remove top unnecessary combination
            k = k % fact;

            // it also equal to fact /= size-1; each time
            fact = fact / numbers.size();
        }
        return ans;
    }
};