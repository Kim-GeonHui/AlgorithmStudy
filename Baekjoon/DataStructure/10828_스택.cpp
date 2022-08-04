#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

struct Stack
{
	int numberArr[100000];
	int index = -1;

	void getSize() {
		cout << index + 1 << endl;
	}

	void push(int X) {
		index++;
		numberArr[index] = X;
	}

	void pop() {
		if (index == -1)
			cout << -1 << endl;
		else {
			cout << numberArr[index] << endl;
			index--;
		}
	}

	void empty() {
		if (index == -1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	void top() {
		if (index == -1)
			cout << -1 << endl;
		else
			cout << numberArr[index] << endl;
	}
};

int main() {

	int N;
	cin >> N;

	Stack stack;
	string str;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> num;
			stack.push(num);
		}
		else if (str == "pop")
			stack.pop();
		else if (str == "top")
			stack.top();
		else if (str == "empty")
			stack.empty();
		else if (str == "size")
			stack.getSize();
	}

	return 0;
}