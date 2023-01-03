#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> nodeArr(N + 1);
	vector<int> visitArr(N + 1);
	vector<int> hackingArr(N + 1);
	vector<int> answerArr;
	
	stack<int> s;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		nodeArr[v].push_back(u);
	}

	int tempNode, tempAnswer;
	for (int i = 1; i <= N; i++) {
		s.push(i);
		tempAnswer = 0;

		while (!s.empty()) {
			tempNode = s.top();
			s.pop();
			if (visitArr[tempNode] == 1) continue;
			visitArr[tempNode] = 1;
			tempAnswer++;
			
			for (auto v : nodeArr[tempNode]) {
				if (visitArr[v] == 1) continue;
				s.push(v);
			}
		}

		hackingArr[i] = tempAnswer;
		fill(visitArr.begin(), visitArr.end(), 0);
	}

	int max = *max_element(hackingArr.begin(), hackingArr.end());
	
	for (int i = 1; i <= N; i++) 
		if (max == hackingArr[i]) answerArr.push_back(i);

	for (auto v : answerArr)
		cout << v << ' ';

	return 0;
}