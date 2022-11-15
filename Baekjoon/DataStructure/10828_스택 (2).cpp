#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

class Node {
public:
	int value;
	Node* next= nullptr;
	Node() {};
	~Node() {};
};

class Stack {
public:
	bool empty();
	void push(int target);
	int pop();
	int size();
	int top();
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
	int num;

	for (int i = 0; i < N; i++) {
		cin >> str;
		
		if (str == "push") {
			cin >> num;
			stack.push(num);
		}
		else if (str == "top")
			cout << stack.top() << '\n';
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

int Stack::top() {
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

int Stack::pop() {
	if (length == 0) return -1;
	
	int answer = topNode->value;
	Node* node = topNode;
	topNode = node->next;
	delete node;
	length--;
	return answer;
}