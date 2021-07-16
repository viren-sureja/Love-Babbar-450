/*
    link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

    sol>set1: https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
    sol>set2: https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Accepted solution
*/
vector<vector<int>> find4Numbers(vector<int>& A, int n, int X)
{
    int l, r;
    vector<vector<int>> ans;
    set<vector<int>> sett;

    sort(A.begin(), A.end());

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            l = j + 1;
            r = n - 1;
            while (l < r)
            {
                if (A[i] + A[j] + A[l] + A[r] == X)
                {
                    sett.insert({ A[i], A[j], A[l], A[r] });
                    l++; r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X) l++;
                else r--;
            }
        }
    }
    for (vector<int> v : sett) ans.push_back(v);
    return ans;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive solution
    TC: O(N^4)
*/

void findFourElements(int A[], int n, int X)
{

// Fix the first element and find other three
    for (int i = 0; i < n - 3; i++)
    {
        // Fix the second element and find other two
        for (int j = i + 1; j < n - 2; j++)
        {

            // Fix the third element and find the fourth
            for (int k = j + 1; k < n - 1; k++)
            {
                // find the fourth
                for (int l = k + 1; l < n; l++)
                    if (A[i] + A[j] + A[k] + A[l] == X)
                        cout << A[i] << ", " << A[j]
                        << ", " << A[k] << ", " << A[l];
            }
        }
    }
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using sorting
    TC: O(N^3)
*/
// C++ program for to print all combination
// of 4 elements in A[] with sum equal to X
#include<bits/stdc++.h>
using namespace std;

/* Following function is needed
for library function qsort(). */
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

/* A sorting based solution to print
all combination of 4 elements in A[]
with sum equal to X */
void find4Numbers(int A[], int n, int X)
{
    int l, r;

    // Sort the array in increasing
    // order, using library function
    // for quick sort
    qsort(A, n, sizeof(A[0]), compare);

    /* Now fix the first 2 elements
    one by one and find
    the other two elements */
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            // Initialize two variables as
            // indexes of the first and last
            // elements in the remaining elements
            l = j + 1;
            r = n - 1;

            // To find the remaining two
            // elements, move the index
            // variables (l & r) toward each other.
            while (l < r)
            {
                if (A[i] + A[j] + A[l] + A[r] == X)
                {
                    cout << A[i] << ", " << A[j] <<
                        ", " << A[l] << ", " << A[r];
                    l++; r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else // A[i] + A[j] + A[l] + A[r] > X
                    r--;
            } // end of while
        } // end of inner for loop
    } // end of outer for loop
}

/* Driver code */
int main()
{
    int A[] = { 1, 4, 45, 6, 10, 12 };
    int X = 21;
    int n = sizeof(A) / sizeof(A[0]);
    find4Numbers(A, n, X);
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Two Pointers Algorithm
    TC: O(n^2)      // if we uses inbuilt sortin algo.
*/
// C++ program to find 4 elements
// with given sum
#include <bits/stdc++.h>
using namespace std;

// The following structure is needed
// to store pair sums in aux[]
class pairSum {
    public:
        // index (int A[]) of first element in pair
    int first;

    // index of second element in pair
    int sec;

    // sum of the pair
    int sum;
};

// Following function is needed
// for library function qsort()
int compare(const void* a, const void* b)
{
    return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
}

// Function to check if two given pairs
// have any common element or not
bool noCommon(pairSum a, pairSum b)
{
    if (a.first == b.first || a.first == b.sec
        || a.sec == b.first || a.sec == b.sec)
        return false;
    return true;
}

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
    int i, j;

    // Create an auxiliary array
    // to store all pair sums
    int size = (n * (n - 1)) / 2;
    pairSum aux[size];

    // Generate all possible pairs
    // from A[] and store sums
    // of all possible pairs in aux[]
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }

    // Sort the aux[] array using
    // library function for sorting
    qsort(aux, size, sizeof(aux[0]), compare);

    // Now start two index variables
    // from two corners of array
    // and move them toward each other.
    i = 0;
    j = size - 1;
    while (i < size && j >= 0) {
        if ((aux[i].sum + aux[j].sum == X)
            && noCommon(aux[i], aux[j])) {
            cout << arr[aux[i].first] << ", "
                << arr[aux[i].sec] << ", "
                << arr[aux[j].first] << ", "
                << arr[aux[j].sec] << endl;
            return;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
}

// Driver code
int main()
{
    int arr[] = { 10, 20, 30, 40, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;

    // Function Call
    findFourElements(arr, n, X);
    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(N^2)
*/
// A hashing based CPP program
// to find if there are
// four elements with given sum.
#include <bits/stdc++.h>
using namespace std;

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
    // Store sums of all pairs
    // in a hash table
    unordered_map<int, pair<int, int> > mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = { i, j };

    // Traverse through all pairs and search
    // for X - (current pair sum).
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            // If X - sum is present in hash table,
            if (mp.find(X - sum) != mp.end()) {

                // Making sure that all elements are
                // distinct array elements and an element
                // is not considered more than once.
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j
                    && p.second != i && p.second != j) {
                    cout << arr[i] << ", " << arr[j] << ", "
                        << arr[p.first] << ", "
                        << arr[p.second];
                    return;
                }
            }
        }
    }
}

// Driver code
int main()
{
    int arr[] = { 10, 20, 30, 40, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;

    // Function call
    findFourElements(arr, n, X);
    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(N^2)
*/
// C++ prgram to find four
// elements with the given sum
#include <bits/stdc++.h>
using namespace std;

// Function to find 4 elements that add up to
// given sum
void fourSum(int X, int arr[], map<int,
    pair<int, int>> Map, int N)
{
    int temp[N];

    // Iterate from 0 to temp.length
    for (int i = 0; i < N; i++)
        temp[i] = 0;

    // Iterate from 0 to arr.length
    for (int i = 0; i < N - 1; i++)
    {

        // Iterate from i + 1 to arr.length
        for (int j = i + 1; j < N; j++)
        {

            // Store curr_sum = arr[i] + arr[j]
            int curr_sum = arr[i] + arr[j];

            // Check if X - curr_sum if present
            // in map
            if (Map.find(X - curr_sum) != Map.end())
            {

                // Store pair having map value
                // X - curr_sum
                pair<int, int> p = Map[X - curr_sum];

                if (p.first != i && p.second != i
                    && p.first != j && p.second != j
                    && temp[p.first] == 0
                    && temp[p.second] == 0 && temp[i] == 0
                    && temp[j] == 0)
                {

                    // Print the output
                    cout << arr[i] << "," << arr[j] <<
                        "," << arr[p.first] << "," << arr[p.second];
                    temp[p.second] = 1;
                    temp[i] = 1;
                    temp[j] = 1;
                    break;
                }
            }
        }
    }
}

// Program for two Sum
map<int, pair<int, int>> twoSum(int nums[], int N)
{
    map<int, pair<int, int>> Map;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            Map[nums[i] + nums[j]].first = i;
            Map[nums[i] + nums[j]].second = j;
        }
    }
    return Map;
}

// Driver code
int main()
{
    int arr[] = { 10, 20, 30, 40, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
    map<int, pair<int, int>> Map = twoSum(arr, n);

    // Function call
    fourSum(X, arr, Map, n);

    return 0;
}
