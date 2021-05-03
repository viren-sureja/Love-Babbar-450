/*
    link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
void threeWayPartition(vector<int>& array, int a, int b)
{
    int low = 0, high = array.size() - 1, mid = 0;

    while (mid <= high) {
        if (array[mid] < a) {
            swap(array[mid++], array[low++]);   // we r sure after swap we won't get <a, bcoz it would have processed earlier.
        }
        else if (array[mid] > b) {
            swap(array[high--], array[mid]);    // here it is possible that after swap we can get >b value again hence no increment in mid.
        }
        else mid++;
    }
}