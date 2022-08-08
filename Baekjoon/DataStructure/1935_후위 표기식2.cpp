#include <stdio.h>
#include <iostream>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	long double number[2];

	string str;
	cin >> str;

	long double numberArr[28];
	for (int i = 1; i < N + 1; i++) {
		cin >> numberArr[i];
	}

	stack<long double> stk;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			number[1] = stk.top();
			stk.pop();
			number[0] = stk.top();
			stk.pop();
			stk.push(number[0] + number[1]);
		}
		else if (str[i] == '-') {
			number[1] = stk.top();
			stk.pop();
			number[0] = stk.top();
			stk.pop();
			stk.push(number[0] - number[1]);
		}
		else if (str[i] == '*') {
			number[1] = stk.top();
			stk.pop();
			number[0] = stk.top();
			stk.pop();
			stk.push(number[0] * number[1]);
		}
		else if (str[i] == '/') {
			number[1] = stk.top();
			stk.pop();
			number[0] = stk.top();
			stk.pop();
			stk.push(number[0] / number[1]);
		}
		else {
			for (int j = 65; j < 65 + N + 1; j++) {
				if (str[i] == j) {
					stk.push(numberArr[j - 64]);
					break;
				}
			}
			
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stk.top();

	return 0;
}