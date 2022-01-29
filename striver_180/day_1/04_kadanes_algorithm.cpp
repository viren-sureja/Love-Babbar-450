/*
    naive approach with 3 for loop
    first 2 loop for starting and ending range
    3rd for the summation
    https://youtu.be/w_KEocd__20?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&t=126

    tc: O(N^3)
*/

/*
    now instead of running summation loop we can sum parallely in end range loop
    https://youtu.be/w_KEocd__20?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&t=180

    tc: O(N^2)
*/



/*
    tc: O(N) sc: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], sum = 0;
        for (int i = 0;i < nums.size();i++) {
            sum = max(sum + nums[i], nums[i]);
            // here just nums[i] means we break the prev sequence as current element is greater than the prev. sum + current element
            mx = max(mx, sum);
        }
        return mx;
    }
};
