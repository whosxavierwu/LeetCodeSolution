// leetcode_1157.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/online-majority-element-in-subarray/
/*
Implementing the class MajorityChecker, which has the following API:

MajorityChecker(int[] arr) constructs an instance of MajorityChecker with the given array arr;
int query(int left, int right, int threshold) has arguments such that:
0 <= left <= right < arr.length representing a subarray of arr;
2 * threshold > right - left + 1, ie. the threshold is always a strict majority of the length of the subarray

Each query(...) 
returns the element in arr[left], arr[left+1], ..., arr[right] 
that occurs at least threshold times, or -1 if no such element exists.

1 <= arr.length <= 20000
1 <= arr[i] <= 20000
For each query, 0 <= left <= right < len(arr)
For each query, 2 * threshold > right - left + 1
The number of queries is at most 10000
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// v1: TLE
//class MajorityChecker {
//	vector<unordered_map<int, int>> mapList;
//public:
//	MajorityChecker(vector<int>& arr) {
//		for (int i = 0; i < arr.size(); ++i) {
//			unordered_map<int, int> tmpMap;
//			if (!mapList.empty())
//				tmpMap = mapList.back();
//			tmpMap[arr[i]] += 1;
//			mapList.push_back(tmpMap);
//		}
//	}
//
//	int query(int left, int right, int threshold) {
//		int result = -1;
//		unordered_map<int, int> tmpMap = mapList[right];
//		for (auto iter = tmpMap.begin(); iter != tmpMap.end(); ++iter) {
//			int curCnt = iter->second;
//			if (left > 0) {
//				auto prevIter = mapList[left - 1].find(iter->first);
//				if (prevIter != mapList[left - 1].end()) 
//					curCnt -= prevIter->second;
//			}
//			if (curCnt >= threshold) {
//				return iter->first;
//			}
//		}
//		return result;
//	}
//};

// v2: TLE
//class MajorityChecker {
//	vector<int> _arr;
//public:
//	MajorityChecker(vector<int>& arr) {
//		_arr = arr;
//	}
//
//	int query(int left, int right, int threshold) {
//		if (threshold > (right - left + 1)) return -1;
//		int key = 0;
//		int cnt = 0;
//		for (int i = left; i <= right; ++i) {
//			if (cnt == 0) key = _arr[i];
//			cnt += (_arr[i] == key) ? 1 : -1;
//		}
//		if (cnt <= 0) return -1;
//		cnt = 0;
//		for (int i = left; i <= right; ++i) {
//			if (_arr[i] == key)
//				++cnt;
//		}
//		return cnt >= threshold ? key : -1;
//	}
//};

// v3 TLE
//class MajorityChecker {
//	unordered_map<int, vector<int>> mmap;
//	vector<int> _arr;
//public:
//	MajorityChecker(vector<int>& arr) {
//		_arr = arr;
//		for (int i = 0; i < arr.size(); ++i) {
//			auto iter = mmap.find(arr[i]);
//			if (iter == mmap.end()) {
//				mmap[arr[i]] = vector<int>(i + 1, 0);
//			}
//			else {
//				while (mmap[arr[i]].size() <= i)
//					mmap[arr[i]].push_back(mmap[arr[i]].back());
//			}
//			mmap[arr[i]][i] += 1;
//		}
//	}
//
//	int query(int left, int right, int threshold) {
//		if (threshold > (right - left + 1)) return -1;
//		int key = 0;
//		int cnt = 0;
//		for (int i = left; i <= right; ++i) {
//			if (cnt == 0) key = _arr[i];
//			cnt += (_arr[i] == key) ? 1 : -1;
//		}
//		if (cnt <= 0) return -1;
//		vector<int> vec = mmap[key];
//		cnt = right >= vec.size() ? vec.back() : vec[right];
//		cnt -= (left > 0 ? mmap[key][left - 1] : 0);
//		return cnt >= threshold ? key : -1;
//	}
//};

// v4: faster than 60.59%
class MajorityChecker {
	unordered_map<int, vector<int>> idxMap;
public:
	MajorityChecker(vector<int>& arr) {
		for (int i = 0; i < arr.size(); ++i) 
			idxMap[arr[i]].push_back(i);
	}
	int query(int left, int right, int threshold) {
		for (auto& iter : idxMap) {
			if (iter.second.size() < threshold) continue;
			auto iter1 = lower_bound(iter.second.begin(), iter.second.end(), left);
			auto iter2 = upper_bound(iter.second.begin(), iter.second.end(), right);
			if (iter2 - iter1 >= threshold) return iter.first;
		}
		return -1;
	}
};

// other solutions: https://leetcode.com/problems/online-majority-element-in-subarray/discuss/356227/C%2B%2B-Codes-of-different-approaches-(Random-Pick-Trade-off-Segment-Tree-Bucket)

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);

 ["MajorityChecker","query","query","query"]
[[[1,1,2,2,1,1]],[0,5,4],[0,3,3],[2,3,2]]

["MajorityChecker","query","query","query","query","query","query","query","query","query","query"]
[[[2,2,1,2,1,2,2,1,1,2]],[2,5,4],[0,5,6],[0,1,2],[2,3,2],[6,6,1],[0,3,3],[4,9,6],[4,8,4],[5,9,5],[0,1,2]]

 */
//int main()
//{
//	vector<int> arr = { 2,2,1,2,1,3,1,1,1,2,3,3,3,1,1,1,2,2,3,3,2,2,1,1,1,2,1,3,1,1,2,3,1,3,3,1,3,2,2,2,3,2,3,1,2,1,3,3,3,2,2,1,1,2,2,3,2,3,3,3,2,1,2,3,1,3,2,3,1,2,3,3,2,2,2,2,2,2,3,2,3,2,3,3,1,2,3,3,3,3,3,3,3,2,1,1,2,1,2,2 };
//	MajorityChecker* obj = new MajorityChecker(arr);
//	cout << obj->query(31, 97, 34) << endl;
//	cout << obj->query(17, 97, 81) << endl;
//	cout << obj->query(20, 48, 28) << endl;
//	cout << obj->query(26, 35, 9) << endl;
//	cout << obj->query(27, 57, 23) << endl;
//	cout << obj->query(13, 74, 37) << endl;
//	cout << obj->query(59, 90, 27) << endl;
//	cout << obj->query(27, 28, 2) << endl;
//	cout << obj->query(0, 57, 47) << endl;
//	cout << obj->query(22, 77, 35) << endl;
//	cout << obj->query(38, 57, 11) << endl;
//	cout << obj->query(37, 80, 30) << endl;
//	cout << obj->query(28, 89, 40) << endl;
//	cout << obj->query(36, 61, 23) << endl;
//	cout << obj->query(28, 70, 36) << endl;
//	cout << obj->query(37, 99, 33) << endl;
//	cout << obj->query(29, 81, 44) << endl;
//	cout << obj->query(81, 81, 1) << endl;
//	cout << obj->query(10, 33, 23) << endl;
//	cout << obj->query(22, 52, 30) << endl;
//	cout << obj->query(8, 22, 12) << endl;
//	cout << obj->query(5, 82, 43) << endl;
//	cout << obj->query(85, 91, 6) << endl;
//	cout << obj->query(27, 75, 40) << endl;
//	cout << obj->query(16, 25, 6) << endl;
//	cout << obj->query(27, 37, 11) << endl;
//	cout << obj->query(7, 95, 89) << endl;
//	cout << obj->query(6, 88, 67) << endl;
//	cout << obj->query(34, 92, 37) << endl;
//	cout << obj->query(17, 86, 57) << endl;
//	cout << obj->query(24, 96, 69) << endl;
//	cout << obj->query(47, 94, 48) << endl;
//	cout << obj->query(45, 68, 22) << endl;
//	cout << obj->query(79, 89, 6) << endl;
//	cout << obj->query(78, 81, 4) << endl;
//	cout << obj->query(23, 85, 54) << endl;
//	cout << obj->query(49, 73, 15) << endl;
//	cout << obj->query(36, 76, 35) << endl;
//	cout << obj->query(20, 50, 28) << endl;
//	cout << obj->query(12, 60, 27) << endl;
//	cout << obj->query(8, 79, 42) << endl;
//	cout << obj->query(14, 94, 43) << endl;
//	cout << obj->query(66, 71, 4) << endl;
//	cout << obj->query(33, 81, 37) << endl;
//	cout << obj->query(28, 84, 32) << endl;
//	cout << obj->query(54, 84, 18) << endl;
//	cout << obj->query(29, 40, 8) << endl;
//	cout << obj->query(12, 63, 39) << endl;
//	cout << obj->query(16, 80, 62) << endl;
//	cout << obj->query(14, 61, 36) << endl;
//	cout << obj->query(31, 65, 29) << endl;
//	cout << obj->query(17, 58, 31) << endl;
//	cout << obj->query(51, 84, 23) << endl;
//	cout << obj->query(19, 95, 65) << endl;
//	cout << obj->query(24, 38, 10) << endl;
//	cout << obj->query(7, 42, 20) << endl;
//	cout << obj->query(0, 73, 60) << endl;
//	cout << obj->query(8, 30, 20) << endl;
//	cout << obj->query(14, 52, 38) << endl;
//	cout << obj->query(2, 50, 36) << endl;
//	cout << obj->query(2, 64, 51) << endl;
//	cout << obj->query(1, 73, 37) << endl;
//	cout << obj->query(75, 87, 9) << endl;
//	cout << obj->query(27, 33, 6) << endl;
//	cout << obj->query(70, 78, 5) << endl;
//	cout << obj->query(52, 98, 43) << endl;
//	cout << obj->query(64, 97, 23) << endl;
//	cout << obj->query(44, 91, 31) << endl;
//	cout << obj->query(39, 44, 5) << endl;
//	cout << obj->query(33, 87, 48) << endl;
//	cout << obj->query(24, 32, 8) << endl;
//	cout << obj->query(45, 70, 18) << endl;
//	cout << obj->query(21, 80, 31) << endl;
//	cout << obj->query(32, 92, 53) << endl;
//	cout << obj->query(38, 85, 37) << endl;
//	cout << obj->query(10, 88, 72) << endl;
//	cout << obj->query(22, 94, 45) << endl;
//	cout << obj->query(13, 15, 3) << endl;
//	cout << obj->query(24, 72, 37) << endl;
//	cout << obj->query(24, 40, 13) << endl;
//	cout << obj->query(24, 80, 48) << endl;
//	cout << obj->query(52, 65, 9) << endl;
//	cout << obj->query(23, 25, 2) << endl;
//	cout << obj->query(63, 74, 11) << endl;
//	cout << obj->query(17, 76, 59) << endl;
//	cout << obj->query(12, 78, 67) << endl;
//	cout << obj->query(89, 89, 1) << endl;
//	cout << obj->query(1, 87, 86) << endl;
//	cout << obj->query(13, 89, 52) << endl;
//	cout << obj->query(50, 60, 7) << endl;
//	cout << obj->query(47, 53, 6) << endl;
//	cout << obj->query(66, 95, 22) << endl;
//	cout << obj->query(4, 86, 52) << endl;
//	cout << obj->query(51, 62, 10) << endl;
//	cout << obj->query(40, 81, 39) << endl;
//	cout << obj->query(26, 42, 10) << endl;
//	cout << obj->query(47, 90, 36) << endl;
//	cout << obj->query(60, 73, 8) << endl;
//	cout << obj->query(7, 57, 37) << endl;
//	cout << obj->query(51, 72, 16) << endl;
//}
