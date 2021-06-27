/*
    link: https://practice.geeksforgeeks.org/problems/circular-tour/1

    sol: https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive approach
    TC: O(N^2)
    SC: O(1)
*/
int tour(petrolPump p[], int n)
{
    bool flag = true;
    int journey = 0;

    // iterating for every point
    for (int i = 0;i < n;i++) {
        journey = 0;
        flag = true;

        // checking that is current point better to start
        for (int j = 0;j < n;j++) {
            // calculating index
            int idx = (i + j) % n;

            // how much petrol we r filling and distance still left to next pump
            journey += p[idx].petrol - p[idx].distance;

            // if journey even once get negative means we were not able to make to next petrol pump
            if (journey < 0) {
                flag = false;
                break;
            }
        }
        // if we r able to cover all the pump
        if (flag) return i;
    }
    // if neither starting point is able to cover all petrol pump
    return -1;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    2 pointer technique

    TC: O(N)
    SC: O(1)
*/

// A petrol pump has petrol and distance to next petrol pump
class petrolPump
{
    public:
    int petrol;
    int distance;
};

// The function returns starting point if there is a possible solution,
// otherwise returns -1
int printTour(petrolPump arr[], int n)
{
    // Consider first petrol pump as a starting point
    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;

    /* Run a loop while all petrol pumps are not visited.
    And we have reached first petrol pump again with 0 or more petrol */
    while (end != start || curr_petrol < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (curr_petrol < 0 && start != end)
        {
            // Remove starting petrol pump. Change start
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;

            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0)
                return -1;
        }

        // Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;

        end = (end + 1) % n;
    }

    // Return starting point
    return start;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    more efficient than previous one
    (as here we find such index whose petrol is more than distance
    and if such index is not able to complete all pumps, then from the pump where we get negative
    value, we start searching for the next such index whose petrol is more than distance.)

    TC: O(N)
    SC: O(1)
*/
// The function returns starting point if there is a
// possible solution, otherwise returns -1
int printTour(petrolPump arr[], int n)
{
    int start;

    for (int i = 0; i < n; i++) {
        // Identify the first petrol pump from where we
        // might get a full circular tour
        if (arr[i].petrol >= arr[i].distance) {
            start = i;
            break;
        }
    }

    // To store the excess petrol
    int curr_petrol = 0;

    int i;

    for (i = start; i < n;) {

        curr_petrol += (arr[i].petrol - arr[i].distance);

        // If at any point remaining petrol is less than 0,
        // it means that we cannot start our journey from
        // current start
        if (curr_petrol < 0) {

            // We move to the next petrol pump
            i++;

            // We try to identify the next petrol pump from
            // where we might get a full circular tour
            for (; i < n; i++) {
                if (arr[i].petrol >= arr[i].distance) {

                    start = i;

                    // Reset rem_petrol
                    curr_petrol = 0;

                    break;
                }
            }
        }

        else {
            // Move to the next petrolpump if curr_petrol is
            // >= 0
            i++;
        }
    }

    // If remaining petrol is less than 0 while we reach the
    // first petrol pump, it means no circular tour is
    // possible
    if (curr_petrol < 0) {
        return -1;
    }

    /*
        as from above for loop we proved that next distance till n are possible with that
        starting point but what for the [0, start) pumps, hence we r checking for those pumps
        and last we r checking in circular fashion [start, end] is checked and [0, start) we r
        checking.
    */
    for (int j = 0; j < start; j++) {

        curr_petrol += (arr[j].petrol - arr[j].distance);

        // If remaining petrol is less than 0 at any point
        // before we reach initial start, it means no
        // circular tour is possibl
        if (curr_petrol < 0) {
            return -1;
        }
    }

    // If we have successfully reached intial_start, it
    // means can get a circular tour from final_start, hence
    // return it
    return start;
}