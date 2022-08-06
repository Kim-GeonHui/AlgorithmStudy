#include <stdio.h>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> que;

	int N;
	cin >> N;

	string str;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> num;
			que.push(num);
		}
		else if (str == "pop") {
			if (que.empty())
				cout << -1 << '\n';
			else {
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (str == "size")
			cout << que.size() << '\n';
		else if (str == "empty") {
			if (que.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "front")
			if (que.empty())
				cout << -1 << '\n';
			else
				cout << que.front() << '\n';
		else if (str == "back")
			if (que.empty())
				cout << -1 << '\n';
			else
				cout << que.back() << '\n';
	}

	return 0;
}