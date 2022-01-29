/*
    naive (just sort them)
    tc: O(N logN) sc: O(1)
*/


/*
    count the 0, 1, 2
    tc: O(N*2) sc: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0, n = nums.size();
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == 0) zero++;
            else if (nums[i] == 1) one++;
            else two++;
        }

        for (int i = 0;i < nums.size();i++) {
            if (zero > 0) {
                nums[i] = 0;
                zero--;
            }
            else if (one > 0) {
                nums[i] = 1;
                one--;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};




/*
    dutch national flag algo.

    tc: O(N) sc: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, mid = 0, r = n - 1;
        while (mid <= r) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[l++]);
            }
            else if (nums[mid] == 1) mid++;
            else {
                swap(nums[mid], nums[r--]);
            }
        }
    }
};