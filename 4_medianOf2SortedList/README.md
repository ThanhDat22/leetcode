# **🧮 Median of Two Sorted Arrays**

## 📘 Problem Description

Given two sorted arrays nums1 and nums2, your task is to find the median of the combined sorted array formed by merging the two. The catch is that you must achieve an overall time complexity of O(log (m+n)), where m and n are the lengths of the two arrays.

Problem is found in [Two Sum](https://leetcode.com/problems/median-of-two-sorted-arrays/).

### Median:

The median is the middle value in a sorted list of numbers.

If the total number of elements is odd, the median is the middle element.

If the total number of elements is even, the median is the average of the two middle elements.

## 📥 Input

Two sorted integer arrays:

nums1 of length m

nums2 of length n

## Constraints

0 <= m <= 1000

0 <= n <= 1000

1 <= m + n <= 2000

-10^6 <= nums1[i], nums2[i] <= 10^6

## 📤 Output

Return the median value of the combined sorted array.

The result must be accurate up to 5 decimal places.

## 🧠 Example 1

```plaintext
Input: nums1 = [1, 3], nums2 = [2]
Merged: [1, 2, 3]
Output: 2.00000
```

Explanation: The median is 2.

## 🧠 Example 2

```plaintext
Input: nums1 = [1, 2], nums2 = [3, 4]
Merged: [1, 2, 3, 4]
Output: 2.50000
```

Explanation: The median is (2 + 3) / 2 = 2.5.

## 🚀 Goal

The naive approach would be to merge the two arrays and then compute the median directly in O(m+n) time. However, to solve this problem efficiently, we aim for a solution that works in O(log(min(m, n))) time by using a binary search technique.

## You code:

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Input your code here     
    }
};
```
