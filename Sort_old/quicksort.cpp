#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
	int pivot = nums[right];
	int i = left;
	for (int j = left; j < right; ++j)
		if (nums[j] < pivot) {
			swap(nums[i], nums[j]);
			i++;
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

int main() {
	vector<int> nums = { 4, 5, 5, 6, 7, 9, 123, 983 };
	quickSort(nums, 0, nums.size() - 1);
	for (int n : nums)
		cout << n << " ";
	cout << endl;
}