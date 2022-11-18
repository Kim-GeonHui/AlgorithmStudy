#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

class Node {
public:
	int value;
	Node* next = nullptr;
	Node() {};
	~Node() {};
};

class Queue {
public:
	bool empty();
	void push(int target);
	int pop();
	int size();
	int front();
	int back();
	Queue() { head = nullptr; tail = nullptr; length = 0; };
	~Queue() { while (!empty()) { pop(); } };
private:
	Node* head;
	Node* tail;
	int length;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Queue queue;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		queue.push(i);
	}

	while (queue.size() > 1) {
		queue.pop();
		queue.push(queue.pop());
	}

	cout << queue.pop();

	return 0;
}

bool Queue::empty() {
	if (length == 0) return 1;
	else return 0;
}

int Queue::size() {
	return length;
}

int Queue::front() {
	if (length == 0) return -1;
	else return head->value;
}

int Queue::back() {
	if (length == 0) return -1;
	else return tail->value;
}

void Queue::push(int target) {
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

int Queue::pop() {
	if (length == 0) return -1;

	int answer = head->value;
	Node* node = head;
	head = node->next;
	delete node;
	length--;
	return answer;
}