/*
    link: https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N)
    SC: O(N)
*/
long swapCount(string s)
{
    // Keep track of '['
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);

    int count = 0; // To count number of encountered '['
    int p = 0; // To track position of next '[' in pos
    long sum = 0; // To store result

    for (int i = 0; i < s.length(); ++i)
    {
        // Increment count and move p to next position
        if (s[i] == '[')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
            --count;

        // We have encountered an unbalanced part of string
        if (count < 0)
        {
            /*
                Increment sum by number of swaps required
                i.e. position of next '[' - current position

                but still why sum+=pos[p]-i and not sum++?
                consider this situation
                    i=2 []]]]]][][
                    now if we observe carefully here ] bracket is at 7th pos
                    and we can only swap adjacent bracket hence that count will be
                    pos[p] - i;
            */
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;

            // Reset count to 1
            count = 1;
        }
    }
    return sum;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N)
    SC: O(1)
*/
long swapCount(string chars)
{

    // Stores total number of Left and
    // Right brackets encountered
    int countLeft = 0, countRight = 0;

    // ans stores the number of swaps
    // required imbalance maintains
    // the number of imbalance pair
    int ans = 0, imbalance = 0;

    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {

            // Increment count of Left bracket
            countLeft++;

            if (imbalance > 0)
            {

                // swaps count is last ans count + total
                // number imbalanced brackets
                ans += imbalance;

                // imbalance decremented by 1 as it solved
                // only one imbalance of Left and Right
                imbalance--;
            }
        }
        else if (chars[i] == ']')
        {

            // Increment count of Right bracket
            countRight++;

            // imbalance is reset to current difference
            // between Left and Right brackets
            imbalance = (countRight - countLeft);
        }
    }
    return ans;
}
