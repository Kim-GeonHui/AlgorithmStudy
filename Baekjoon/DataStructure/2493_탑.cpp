#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> answer;
	stack<pair<int, int>> stk;
	int tempNum;

	cin >> tempNum;
	stk.push({ 1, tempNum });
	answer.push_back(0);

	for (int i = 2; i <= N; i++) {
		cin >> tempNum;

		while (!stk.empty()) {
			if (stk.top().second > tempNum) {
				answer.push_back(stk.top().first);
				break;
			}
			else if (stk.top().second == tempNum) {
				answer.push_back(stk.top().first);
				stk.pop();
				break;
			}
			else {
				if (stk.size() == 1) answer.push_back(0);
				stk.pop();
			}
		}
		stk.push({ i, tempNum });
	}

	for (int i = 0; i < answer.size(); i++) cout << answer[i] << ' ';

	return 0;
}