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

	int answer = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') stk.push(str[i]);
		else {
			stk.pop();
			if (str[i - 1] == '(') answer += stk.size();
			else answer += 1;
		}
	}

	cout << answer;
	
	return 0;
}