#include <stdio.h>
#include <iostream>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	stack<char> stk;
	int num[32] = {0};

	for (int i = 0; i < str.size(); i++) {
		if (stk.size() == 0) {
			stk.push(str[i]);
			continue;
		}

		if (str[i] == ')' && stk.top() == '(') {
			if (num[stk.size() + 1] == 0) num[stk.size()] += 2;
			else {
				num[stk.size()] += 2 * num[stk.size() + 1];
				num[stk.size() + 1] = 0;
			}
			stk.pop();
		}
		else if (str[i] == ']' && stk.top() == '[') {
			if (num[stk.size() + 1] == 0) num[stk.size()] += 3;
			else {
				num[stk.size()] += 3 * num[stk.size() + 1];
				num[stk.size() + 1] = 0;
			}
			stk.pop();
		}
		else stk.push(str[i]);
	}

	if (stk.size() != 0) cout << 0 << '\n';
	else cout << num[1] << '\n';

	return 0;
}