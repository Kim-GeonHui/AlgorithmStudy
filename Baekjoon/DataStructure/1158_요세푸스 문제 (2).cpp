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

	int N, K;
	cin >> N >> K;

	vector<int> visit(N + 1, false);
	
	int index = 0;
	int count = 0;

	while (stack.size() != N) {
		count = 0;
		while (count < K) {
			index++;
			if (index > N) index -= N;
			if (!visit[index]) count++;
		}

		visit[index] = true;
		stack.push(index);
	}

	cout << '<';
	for (int i = 0; i < N - 1; i++) {
		cout << stack.pop() << ',' << ' ';
	}
	cout << stack.pop() << '>';

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