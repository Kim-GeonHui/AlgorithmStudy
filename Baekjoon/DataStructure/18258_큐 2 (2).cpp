#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

class Node {
public:
	int value;
	Node* next = nullptr;
	Node() {};
	~Node() {};
};

class Stack {
public:
	bool empty();
	void push(int target);
	int pop();
	int size();
	int front();
	int back();
	Stack() { head = nullptr; tail = nullptr; length = 0; };
	~Stack() { while (!empty()) { pop(); } };
private:
	Node* head;
	Node* tail;
	int length;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Stack stack;

	int N;
	cin >> N;

	string str;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> num;
			stack.push(num);
		}
		else if (str == "front")
			cout << stack.front() << '\n';
		else if (str == "back")
			cout << stack.back() << '\n';
		else if (str == "pop")
			cout << stack.pop() << '\n';
		else if (str == "size")
			cout << stack.size() << '\n';
		else if (str == "empty")
			cout << stack.empty() << '\n';
	}

	return 0;
}

bool Stack::empty() {
	if (length == 0) return 1;
	else return 0;
}

int Stack::size() {
	return length;
}

int Stack::front() {
	if (length == 0) return -1;
	else return head->value;
}

int Stack::back() {
	if (length == 0) return -1;
	else return tail->value;
}

void Stack::push(int target) {
	Node* node = new Node;
	node->value = target;

	if (length == 0) {
		head = node;
		tail = node;
		length++;
		return;
	}
	else {
		tail->next = node;
		tail = tail->next;
		length++;
	}
}

int Stack::pop() {
	if (length == 0) return -1;

	int answer = head->value;
	Node* node = head;
	head = node->next;
	delete node;
	length--;
	return answer;
}