// leetcode_1146.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SnapshotArray {
	int snap_id;
	vector<vector<int>> mmap;
public:
	SnapshotArray(int length) {
		snap_id = 0;
		mmap.resize(length);
	}

	void set(int index, int val) {
		int t = (!mmap[index].empty()) ? mmap[index].back() : 0;
		if (snap_id >= mmap[index].size()) {
			for (int i = mmap[index].size(); i <= snap_id; ++i)
				mmap[index].push_back(t);
		}
		mmap[index][snap_id] = val;
	}

	int snap() {
		int tmp = snap_id;
		snap_id++;
		return tmp;
	}

	int get(int index, int snap_id) {
		if (mmap[index].empty())
			return 0;
		if (snap_id >= mmap[index].size()) {
			return mmap[index].back();
		}
		else {
			return mmap[index][snap_id];
		}
	}
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main()
{
	SnapshotArray* obj = new SnapshotArray(3);
	obj->set(1, 18);
	obj->set(1, 4);
	cout << obj->snap() << endl;
	cout << obj->get(0, 0) << endl;
	obj->set(0, 20);
	cout << obj->snap() << endl;
	obj->set(0, 2);
	obj->set(1, 1);
	cout << obj->get(1, 1) << endl;
	cout << obj->get(1, 0) << endl;
}
