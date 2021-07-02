/*
    link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

    logic: iterate mid and if mid==0 then swap with low and then low++, mid++
           if mid==2 then swap with high and then high--, mid
           else mid++ as it would be 1.

    variation: 2-pointer
*/



// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int low = 0, high = n - 1, mid = 0;
    while (mid <= high) {
        if (a[mid] == 0) swap(a[mid++], a[low++]);
        else if (a[mid] == 1) mid++;
        else swap(a[mid], a[high--]);
        /* why not mid++ ?
            ans: let's assume the one which with we are swapping is also 2 then after swapping in mid pos it will still be 2
                hence solution is don't increment the mid until and unless it is equal to 1.
        */
    }
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n = 5;
    int arr[] = { 0, 2, 1, 2, 0 };
    sort012(arr, n);
}
