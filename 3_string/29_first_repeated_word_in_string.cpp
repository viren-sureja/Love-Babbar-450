/*
    link: https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using map

    we would have use the stack (priority_queue of min_heap as we want to remove minimum freq from the top)
    for the same but will occupy the space.
*/

string secFrequent(string arr[], int n)
{
    //code here.
    map<string, int> mp;
    int mx = INT_MIN;
    for (int i = 0;i < n;i++) {
        mp[arr[i]]++;
        mx = max(mx, mp[arr[i]]);
    }
    int new_mx = INT_MIN;
    string ans;

    // as we know the highest freq. now find the second highest freq.
    for (auto i = mp.begin();i != mp.end();i++) {
        if (i->second != mx && i->second > new_mx) {
            new_mx = i->second;
            ans = i->first;
        }
    }
    return ans;
}