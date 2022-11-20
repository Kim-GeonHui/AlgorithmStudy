#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

class Node {
public:
	double value;
	Node* next = nullptr;
	Node() {};
	~Node() {};
};

class Stack {
public:
	bool empty();
	void push(double target);
	double pop();
	int size();
	double top();
	Stack() { front = nullptr; length = 0; };
	~Stack() { while (!empty()) { pop(); } };
private:
	Node* front;
	int length;
};

int main() {
	Stack stack;

	cout << fixed;
	cout.precision(2);

	int N;
	cin >> N;

	string str;
	cin >> str;

	double alphabet[26] = {};
	for (int i = 0; i < N; i++) {
		cin >> alphabet[i];
	}

	double num1, num2;
	for (int i = 0; i < str.length(); i++) {
		if (65 <= str[i] && str[i] <= 90) 
			stack.push(alphabet[str[i] - 65]);
		else {
			num2 = stack.pop();
			num1 = stack.pop();

			if (str[i] == '+')
				stack.push(num1 + num2);
			else if (str[i] == '-')
				stack.push(num1 - num2);
			else if (str[i] == '*')
				stack.push(num1 * num2);
			else if (str[i] == '/')
				stack.push(num1 / num2);
		}
	}

	cout << stack.pop() << '\n';

	return 0;
}

bool Stack::empty() {
	if (length == 0) return 1;
	else return 0;
}

int Stack::size() {
	return length;
}

double Stack::top() {
	if (length == 0) return -1;
	else return front->value;
}

void Stack::push(double target) {
	Node* node = new Node;
	node->value = target;

	node->next = front;
	front = node;
	length++;
}

double Stack::pop() {
	if (length == 0) return -1;

	double answer = front->value;
	Node* node = front;
	front = node->next;
	delete node;
	length--;
	return answer;
}