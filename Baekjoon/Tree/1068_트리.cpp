#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

map<int, vector<int>> nodeMap;
int answer = 0;

void findAnswer(int node, int target) {
	if (node == target) return;
	
	if (nodeMap[node].size() == 0) {
		answer++;
		return;
	}
	else {
		int size = nodeMap[node].size();
		for (int i = 0; i < size; i++) {
			if (nodeMap[node][i] == target && size == 1) {
				answer++;
				return;
			}
			else findAnswer(nodeMap[node][i], target);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, target, tempNum, root;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> tempNum;

		if (tempNum == -1) root = i;
		else nodeMap[tempNum].push_back(i);
	}

	cin >> target;
	findAnswer(root, target);
	cout << answer << '\n';

	return 0;
}