// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-an-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* quickSort */
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int firstBigIdx = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivot) {
                swap(nums[firstBigIdx], nums[i]);
                firstBigIdx++;
            }
        }
        swap(nums[firstBigIdx], nums[right]);
        return firstBigIdx;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pivotIdx = partition(nums, left, right);
        quickSort(nums, left, pivotIdx - 1);
        quickSort(nums, pivotIdx + 1, right);
    }

    /* mergeSort */
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                tmp.push_back(nums[i++]);
            else
                tmp.push_back(nums[j++]);
        }
        while (i <= mid)
            tmp.push_back(nums[i++]);
        while (j <= right)
            tmp.push_back(nums[j++]);
        for (int k = 0; k < tmp.size(); ++k)
            nums[left + k] = tmp[k];
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    /* heapSort */
    void heapify(vector<int>& nums, int heapSize, int rootIdx) {
        int largestIdx = rootIdx;
        int leftIdx = rootIdx * 2 + 1;
        int rightIdx = rootIdx * 2 + 2;
        if (leftIdx < heapSize && nums[leftIdx] > nums[largestIdx])
            largestIdx = leftIdx;
        if (rightIdx < heapSize && nums[rightIdx] > nums[largestIdx])
            largestIdx = rightIdx;
        if (largestIdx != rootIdx) {
            swap(nums[rootIdx], nums[largestIdx]);
            heapify(nums, heapSize, largestIdx);
        }
    }
    void heapSort(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(nums, n, i);
        for (int lastUnsortedIdx = n - 1; lastUnsortedIdx >= 0; --lastUnsortedIdx) {
            swap(nums[0], nums[lastUnsortedIdx]);
            heapify(nums, lastUnsortedIdx, 0);
        }
    }
    /* main fuction */
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        //mergeSort(nums, 0, nums.size() - 1);
        //heapSort(nums);
        return nums;
    }
};


int main()
{
    vector<int> arr = { 1, 2, 3, 123, 3, 4, 5, 999, 666 };
    Solution sol;
    arr = sol.sortArray(arr);
    for (int a : arr)
        cout << a << " ";
    cout << endl;
    return 0;
}
