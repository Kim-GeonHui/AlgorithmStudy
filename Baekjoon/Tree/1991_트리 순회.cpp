#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#pragma warning (disable:4996)

using namespace std;

map<char, pair<char, char>> nodeMap;

void preorder(char rootNode) {
	cout << rootNode;
	if (nodeMap[rootNode].first != '.') preorder(nodeMap[rootNode].first);
	if (nodeMap[rootNode].second != '.') preorder(nodeMap[rootNode].second);
}

void inorder(char rootNode) {
	if (nodeMap[rootNode].first != '.') inorder(nodeMap[rootNode].first);
	cout << rootNode;
	if (nodeMap[rootNode].second != '.') inorder(nodeMap[rootNode].second);
}

void postorder(char rootNode) {
	if (nodeMap[rootNode].first != '.') postorder(nodeMap[rootNode].first);
	if (nodeMap[rootNode].second != '.') postorder(nodeMap[rootNode].second);
	cout << rootNode;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	char node1, node2, node3;

	for (int i = 0; i < N; i++) {
		cin >> node1 >> node2 >> node3;
		nodeMap[node1] = { node2, node3 };
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
}