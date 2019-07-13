// leetcode_1114.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/print-in-order/

#include <iostream>
#include <functional>
#include <mutex>
#include <atomic>
using namespace std;

// v1
class Foo {
	mutex m1, m2;
public:
	Foo() {
		m1.lock();
		m2.lock();
	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		m1.unlock();
	}

	void second(function<void()> printSecond) {
		m1.lock();
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		m1.unlock();
		m2.unlock();
	}

	void third(function<void()> printThird) {
		m2.lock();
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
		m2.unlock();
	}
};

// v2 much slower
class Foo {
	atomic_int semaphore;
public:
	Foo() : semaphore(0) {
		
	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		semaphore = 1;
	}

	void second(function<void()> printSecond) {
		while (semaphore != 1);
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		semaphore = 2;
	}

	void third(function<void()> printThird) {
		while (semaphore != 2);
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};


int main()
{
    std::cout << "Hello World!\n";
}

