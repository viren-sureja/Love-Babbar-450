/*
    link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using array of 256 to store occurence count
    TC: O(n)
    SC: O(256) => O(1) constant
*/
void print_duplicates(string s, int n) {
    int arr[256];   // 256 as its not said there would be only alphabets
    memset(arr, 0, sizeof(arr));
    for (char c : s) {
        arr[c - 'a']++;
    }
    for (int i = 0;i < 256;i++) {
        if (arr[i] > 1) {   // greater than 1 as we have to find the duplicates
            cout << ('a' + i), << " Count=" << arr[i] << endl;
        }
    }
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using maps
    TC:
*/

void print_duplicates(string s, int n) {
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }


    for (auto i = mp.begin();i != mp.end();i++) {
        if (i->second > 1) {
            cout << i->first, << " Count=" << i->second << endl;
        }
    }
    // another way to access map
    /*
        for (auto it : count) {
            if (it.second > 1)
                cout << it.first << ", count = " << it.second
                    << "\n";
        }
    */
}