#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
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
	Queue priority;

	int T;
	cin >> T;

	int N, M;
	vector<int> arr;
	vector<int> tempArr;
	int answer;
	int tempNum;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		arr.assign(N, 0);
		tempArr.assign(N, 0);
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
			tempArr[j] = arr[j];
			queue.push(j + 1);
		}

		sort(tempArr.rbegin(), tempArr.rend());
		for (int j = 0; j < N; j++) {
			priority.push(tempArr[j]);
		}
		answer = 1;

		while (!queue.empty()) {
			if (arr[queue.front() - 1] == priority.front()) {
				if (queue.front() - 1 == M) {
					cout << answer << '\n';
					break;
				}
				else {
					queue.pop();
					priority.pop();
					answer++;
				}
			}
			else {
				tempNum = queue.pop();
				queue.push(tempNum);
			}
		}

		while (!priority.empty()) { priority.pop(); }
		while (!queue.empty()) { queue.pop(); }
		
		arr.clear();
		tempArr.clear();
	}

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