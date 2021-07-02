/*
    link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

    logic:
        1. sort by profit so that we can prioritize the best
        2. now for every job find :
            a. if the current job is empty then fill it
            b. if not the current job then find the job slot which is empty and having deadline less than current

    warning: we cannot the replace the filled job as if the job exist for that deadline then we have to fill it.
*/



// ----------------------------------------------------------------------------------------------------------------------- //
bool static compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

class Solution
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, compare);
        int a[n + 1];
        memset(a, 0, sizeof(a));
        for (int i = 0;i < n;i++) {
            for (int j = min(arr[i].dead, n);j > 0;j--) {
                if (a[j] == 0) {
                    a[j] = arr[i].profit;
                    break;
                }
            }
        }
        int cnt = 0, ans = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i] != 0) {
                cnt++;
                ans += a[i];
            }
        }
        return { cnt, ans };
    }
};