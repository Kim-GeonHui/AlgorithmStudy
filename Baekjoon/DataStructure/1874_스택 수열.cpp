#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
	int top();
	Stack() { topNode = nullptr; length = 0; };
	~Stack() { while (!empty()) { pop(); } };
private:
	Node* topNode;
	int length;
};

int main() {
	Stack stack;

	queue<char> que;

	int N;
	cin >> N;

	vector<int> tempAnswer(N, 0);
	vector<int> arr(N, 0);
	int pushCount = 0;
	int popCount = 0;
	int tempIndex = 0;

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < arr[0]; i++) {
		stack.push(i + 1);
		pushCount++;
		que.push('+');
	}
	tempAnswer[0] = stack.pop();
	tempIndex++;
	popCount++;
	que.push('-');
	
	while (tempAnswer[tempIndex - 1] != N) {
		if (stack.top() < arr[tempIndex]) {
			for (int j = pushCount + 1; j <= arr[tempIndex]; j++) {
				stack.push(j);
				pushCount++;
				que.push('+');
			}
			tempAnswer[tempIndex] = stack.pop();
			popCount++;
			tempIndex++;
			que.push('-');
		}
		else {
			while (arr[tempIndex] <= stack.top()) {
				tempAnswer[tempIndex] = stack.pop();
				popCount++;
				tempIndex++;
				que.push('-');
			}
		}
	}

	while (!stack.empty()) {
		tempAnswer[tempIndex] = stack.pop();
		tempIndex++;
		popCount++;
		que.push('-');
	}

	if (tempAnswer == arr) {
		while (!que.empty()) {
			cout << que.front() << '\n';
			que.pop();
		}
	}
	else cout << "NO" << '\n';

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