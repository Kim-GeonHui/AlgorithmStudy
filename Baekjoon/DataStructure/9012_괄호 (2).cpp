#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

class Node {
public:
	char value;
	Node* next= nullptr;
	Node() {};
	~Node() {};
};

class Stack {
public:
	bool empty();
	void push(int target);
	void pop();
	int size();
	char top();
	Stack() { topNode = nullptr; length = 0; };
	~Stack() { while (!empty()) { pop(); } };
private:
	Node* topNode;
	int length;
};

int main() {
	Stack stack;

	int N;
	cin >> N;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') stack.push(str[j]);
			else if (stack.top() == '(') stack.pop();
			else stack.push(str[j]);
		}

		if (stack.size() == 0)
			cout << "YES" << '\n';
		else cout << "NO" << '\n';

		while (!stack.empty()) { stack.pop(); }
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

char Stack::top() {
	if (length == 0) return -1;
	else return topNode->value;
}

void Stack::push(int target) {
	Node* node = new Node;
	node->value = target;
	
	node->next = topNode;
	topNode = node;
	length++;
}

void Stack::pop() {
	if (length == 0) return;
	
	Node* node = topNode;
	topNode = node->next;
	delete node;
	length--;
}