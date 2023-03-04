#pragma once
#include <string.h>
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
	T* ptr;
	int size = 10;
	int top = -1;
	Stack() {
		cout << "Stack default constructor" << endl;
		ptr = new T[size];
	}
	Stack(int N) {
		cout << "Stack(N) constructor" << endl;
		size = N;  ptr = new T[size];
	}
	void print(void) {
		for (int i = 0; i <= top; i++) {
			cout << ptr[i] << endl;
		}
	}
	void push(T value) { top++; *(ptr + top) = value; }
	T pop(void) { top--; return *(ptr + top + 1); }
	int stack_size(void) {
		return size;
	}
	T peek(void) { return ptr[top]; }
	int isEmpty(void) {
		if (top == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int isFull(void) { top == size - 1 ? 1 : 0; }

	bool balance(string x) {
		Stack<char> seq;
		for (int i = 0; i < x.size(); i++) {
			cout << "Print x sub i " << x[i] << endl;
			if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
				cout << "In case A" << endl;
				seq.push(x[i]);
				cout << "After push " << x[i] << endl;
			}
			cout << "Hello" << endl;
			cout << "Printing top of stack" << seq.top << endl;
			if (seq.peek() == '(' && x[i] == ')' ||
				seq.peek() == '[' && x[i] == ']' ||
				seq.peek() == '{' && x[i] == '}') {
				cout << "After pop" << seq.pop() << endl;
				cout << "In case B" << x[i] << endl;
				if (seq.isEmpty()) {
					return true;
				}
			}
		}
		return false;
	}

	void multipop(int k);
};

template <class T>
void Stack<T>::multipop(int k) {
	cout << "In function multipop" << endl;
	if (this->isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		for (int i = 0; i <= k; i++) {
			if (this->isEmpty()) {
				cout << "Stack is empty now" << endl;
			}
			else {
				this->pop();
			}
		}
	}
}



