/*
    link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
int findLongestConseqSubseq(int arr[], int N)
{
    //Your code here
    int range = 1e6;
    int cnt[range];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0;i < N;i++) {
        cnt[arr[i]]++;
    }
    int local = 0, global = 0;
    for (int i = 0;i < range;i++) {
        if (cnt[i] > 0) local++;
        else local = 0;
        global = max(global, local);
    }
    return global;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// using hashing
int findLongestConseqSubseq(int arr[], int n)
{
    //using a Set to store elements.
    unordered_set<int> S;
    int ans = 0;

    //inserting all the array elements in Set.
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

     //checking each possible sequence from the start.
    for (int i = 0; i < n; i++)
    {
       //if current element is starting element of a sequence then only 
       //we try to find out the length of sequence.
        if (S.find(arr[i] - 1) == S.end())
        {

            int j = arr[i];
            //then we keep checking whether the next consecutive elements
            //are present in Set and we keep incrementing the counter.
            while (S.find(j) != S.end())
                j++;

            //storing the maximum count.
            ans = max(ans, j - arr[i]);
        }
    }
    //returning the length of longest subsequence
    return ans;
}