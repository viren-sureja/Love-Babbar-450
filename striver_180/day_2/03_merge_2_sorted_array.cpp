/*
    brute force
    take an array fill from both and sort

    Time complexity: O(n*log(n))+O(n)+O(n)
    Space Complexity: O(n)

*/

/*
    space optimized
    swap ele if ele is greater in first array and sort second array everytime.

    Time complexity: O(n*m)
    Space Complexity: O(1)
*/

/*
    time optimized
    gap method

    tc: O(log2(n+m)) * O(n+m)
        [O(n+m)] if in nums1 all the elements are greater than nums2
    sc: O(1)
*/

class Solution {
public:
    int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap, i, j;
        gap = n + m;
        for (gap = nextGap(gap);gap > 0;gap = nextGap(gap)) {
            for (i = 0;i + gap < m;i++) {
                if (nums1[i] > nums1[i + gap]) swap(nums1[i], nums1[i + gap]);
            }
            for (j = (gap > m) ? gap - m : 0; i < m && j < n; i++, j++) {
                if (nums1[i] > nums2[j]) swap(nums1[i], nums2[j]);
            }
            if (j < n) {
                for (j = 0;j + gap < n;j++) {
                    if (nums2[j] > nums2[j + gap]) swap(nums2[j], nums2[j + gap]);
                }
            }
        }

        // extra code as in leetcode it is asked to modify the nums1
        for (int i = m;i < m + n;i++) {
            nums1[i] = nums2[i - m];
        }
    }
};