/*
    link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

    sol: https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive solution (run 2 for loops)
    TC: O(n^2)
*/





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(N)
    SC: O(N)
*/
ll findSubarray(vector<ll> arr, int n) {

    ll sum = 0, counter = 0;

    //using map to store the prefix sum which has appeared already.
    unordered_map<ll, ll>mp;

       //iterating over the array.
    for (int i = 0;i < n;i++)
    {
        //storing prefix sum.
        sum += arr[i];

        //if prefix sum is zero that means we get a subarray with sum=0.
        if (sum == 0)
        {
            //incrementing the counter.
            counter++;
        }

        //if prefix sum is already present in map then it is repeated 
        //which means there is a subarray whose summation is 0.
        if (mp.count(sum) != 0)
        {
           //we add the value at prefix sum in map to counter.
            counter += mp[sum];         // LOGIC TO COUNT SUBARRAY IN BETWEEN
        }

        //incrementing the count of prefix sum obtained in map.
        mp[sum]++;
    }
   //returning the counter.
    return counter;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing (but to print)
*/


vector< pair<int, int> > findSubArrays(int arr[], int n)
{
    // create an empty map
    unordered_map<int, vector<int> > map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector <pair<int, int>> out;

    // Maintains sum of elements so far
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Important - no else
        map[sum].push_back(i);
    }

    // return output vector
    return out;
}

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        cout << "Subarray found from Index " <<
        it->first << " to " << it->second << endl;
}

// Driver code
int main()
{
    int arr[] = { 6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int> > out = findSubArrays(arr, n);

    // if we didn’t find any subarray with 0 sum,
    // then subarray doesn’t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out);

    return 0;
}
