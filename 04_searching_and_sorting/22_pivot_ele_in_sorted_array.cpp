/*
    link: http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/

    note: The pivot element is basically, the largest element in an array
    still it depends upon the question
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    binary search (it's given divide and conquer in website but it's not true)
    TC: O(logn)
    SC: O(1)
*/
int peakElement(int arr[], int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;

    if (mid == lowerBound) {
        if (mid == upperBound) {
            // Only 1 element
            return mid;
        }
        else if (arr[mid] >= arr[mid + 1]) {
         // Pivot is the greater element
            return mid;
        }
    }
    else if (mid == upperBound) {
        if (arr[mid] >= arr[mid - 1]) {
            // Pivot is the greater element
            return mid;
        }
    }
    else {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) {
            // Mid value is the pivot
            return mid;
        }
        else if (arr[mid] > arr[high]) {
         // The Pivot is in the second half
            return peakElement(arr, mid + 1, high, lowerBound, upperBound);
        }
        else if (arr[mid] < arr[high]) {
         // The Pivot is in the first half
            return peakElement(arr, low, mid - 1, lowerBound, upperBound);
        }
    }

    return -1;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    binary search
    TC: O(logn)
    SC: O(1)
*/
int peakElement(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == arr[high]) return mid;
    else if (arr[mid] > arr[high]) {
        peakElement(arr, mid, high);
    }
    else if (arr[mid] < arr[high]) {
        peakElement(arr, low, mid - 1);
    }
    return -1;
}