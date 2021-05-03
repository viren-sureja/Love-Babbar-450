/*
    link: https://practice.geeksforgeeks.org/problems/common-elements1132/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
vector <int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    set<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < n1 and j < n2 and k < n3) {
        if (a[i] == b[j] && a[i] == c[k]) {
            ans.insert(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j] || a[i] < c[k]) i++;
        else if (b[j] < a[i] || b[j] < c[k]) j++;
        else if (c[k] < b[j] || c[k] < a[i]) k++;
    }
    vector<int> nn;
    for (ele : ans) {
        nn.push_back(ele);
    }
    return nn;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// alternate solution (improved)
vector <int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;

    vector <int> res;
    int last = INT_MIN;
    while (i < n1 and j < n2 and k < n3)
    {
        if (A[i] == B[j] and A[i] == C[k] and A[i] != last)
        {
            res.push_back(A[i]);
            last = A[i];
            i++;
            j++;
            k++;
        }
        else if (min({ A[i], B[j], C[k] }) == A[i]) i++;
        else if (min({ A[i], B[j], C[k] }) == B[j]) j++;
        else k++;
    }
    return res;
}