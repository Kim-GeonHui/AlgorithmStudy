#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	string str;

	stack<char> stk;

	for (int i = 0; i < T; i++) {
		cin >> str;

		if (str.size() % 2 == 1) {
			cout << "NO" << '\n';
			continue;
		}

		if (str[0] == ')') {
			cout << "NO" << '\n';
			continue;
		}

		for (int j = 0; j < str.size(); j++) {
			if (stk.empty()) {
				stk.push(str[j]);
				continue;
			}
			
			if (stk.top() == '(' && str[j] == ')')
				stk.pop();
			else
				stk.push(str[j]);
		}

		if (stk.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		while (!stk.empty())
			stk.pop();
	}

	return 0;
}