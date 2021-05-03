/*
    link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
// SC: O(N)
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> s;
    for (int i = 0;i < n;i++) {
        s.insert(a1[i]);
    }
    for (int i = 0;i < m;i++) {
        if (s.find(a2[i]) == s.end()) return "No";
    }
    return "Yes";
}



// ----------------------------------------------------------------------------------------------------------------------- //
// similar solution.
string isSubset(int a1[], int a2[], int n, int m) {

    unordered_map<int, int> um, um2;

    for (int i = 0; i < n; i++) {
        um[a1[i]]++;
    }
    for (int i = 0; i < m; i++) {
        um2[a2[i]]++;
    }

    int count = 0;
    for (auto it = um2.begin(); it != um2.end(); it++) {
        if (um[it->first] >= it->second) {
            count++;
        }
    }

    if (count == m)
        return "Yes";
    else
        return "No";
}