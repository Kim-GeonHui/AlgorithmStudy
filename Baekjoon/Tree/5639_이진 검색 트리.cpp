#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#pragma warning (disable:4996)

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int _data) {
		data = _data;
		left = NULL;
		right = NULL;
	}
};

void printNode(Node* node) {
	if (node->left != NULL) printNode(node->left);
	if (node->right != NULL) printNode(node->right);
	cout << node->data << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int node, tempNode;
	bool isEnd;
	cin >> node;
	Node* rootNode = new Node(node);

	while (cin >> node) {

		isEnd = false;
		Node* tempNode = rootNode;
		while (!isEnd) {
			if (tempNode->data > node) {
				if (tempNode->left == NULL) {
					Node* insertNode = new Node(node);
					tempNode->left = insertNode;
					isEnd = true;
				}
				else {
					tempNode = tempNode->left;
					continue;
				}
			}
			else {
				if (tempNode->right == NULL) {
					Node* insertNode = new Node(node);
					tempNode->right = insertNode;
					isEnd = true;
				}
				else {
					tempNode = tempNode->right;
					continue;
				}
			}
		}
	}

	printNode(rootNode);

	return 0;
}