// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/sort-an-array/

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; ++j)
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIdx = partition(arr, left, right);
        quickSort(arr, left, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, right);
    }
}

class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivotIdx = partition(nums, left, right);
            quickSort(nums, left, pivotIdx - 1);
            quickSort(nums, pivotIdx + 1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    vector<int> arr = { 1, 2, 3, 123, 3, 4, 5, 999, 666 };
    quickSort(arr, 0, arr.size() - 1);
    for (int a : arr)
        cout << a << " ";
    cout << endl;
    return 0;
}
