#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

class Node {
public:
	int value;
	Node* next = nullptr;
	Node* front = nullptr;
	Node() {};
	~Node() {};
};

class Deque {
public:
	bool empty();
	void push_front(int target);
	void push_back(int target);
	int pop_front();
	int pop_back();
	int size();
	int front();
	int back();
	Deque() { head = nullptr; tail = nullptr; length = 0; };
	~Deque() { while (!empty()) { pop_front(); } };
private:
	Node* head;
	Node* tail;
	int length;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Deque deque;

	int N;
	cin >> N;

	string str;
	int target = 0;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push_back") {
			cin >> target;
			deque.push_back(target);
		}
		else if (str == "push_front") {
			cin >> target;
			deque.push_front(target);
		}
		else if (str == "pop_front")
			cout << deque.pop_front() << '\n';
		else if (str == "pop_back")
			cout << deque.pop_back() << '\n';
		else if (str == "size")
			cout << deque.size() << '\n';
		else if (str == "empty")
			cout << deque.empty() << '\n';
		else if (str == "front")
			cout << deque.front() << '\n';
		else if (str == "back")
			cout << deque.back() << '\n';
	}

	return 0;
}

bool Deque::empty() {
	if (length == 0) return 1;
	else return 0;
}

int Deque::size() {
	return length;
}

int Deque::front() {
	if (length == 0) return -1;
	else return head->value;
}

int Deque::back() {
	if (length == 0) return -1;
	else return tail->value;
}

void Deque::push_front(int target) {
	Node* node = new Node;
	node->value = target;

	if (length == 0) {
		head = node;
		tail = node;
		length++;
		return;
	}

	node->next = head;
	head->front = node;
	head = node;
	length++;
}

void Deque::push_back(int target) {
	Node* node = new Node;
	node->value = target;

	if (length == 0) {
		head = node;
		tail = node;
		length++;
		return;
	}

	tail->next = node;
	node->front = tail;
	tail = tail->next;
	length++;
}

int Deque::pop_front() {
	if (length == 0) return -1;	

	int answer = head->value;
	Node* node = head;
	head = node->next;
	node->next = nullptr;
	delete node;
	length--;
	 
	return answer;
}

int Deque::pop_back() {
	if (length == 0) return -1;

	int answer = tail->value;
	Node* node = tail;
	if (length != 1) {
		tail = node->front;
		tail->next = nullptr;
	}
	delete node;
	length--;

	return answer;
}