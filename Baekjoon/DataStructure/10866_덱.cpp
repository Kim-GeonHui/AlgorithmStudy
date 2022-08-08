#include <stdio.h>
#include <iostream>
#include <deque>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	deque<int> que;
	string str;
	int tempNumber;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push_front") {
			cin >> tempNumber;
			que.push_front(tempNumber);
		}
		else if (str == "push_back") {
			cin >> tempNumber;
			que.push_back(tempNumber);
		}
		else if (str == "pop_front") {
			if (que.empty())
				cout << -1 << '\n';
			else {
				cout << que.front() << '\n';
				que.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (que.empty())
				cout << -1 << '\n';
			else {
				cout << que.back() << '\n';
				que.pop_back();
			}
		}
		else if (str == "size")
			cout << que.size() << '\n';
		else if (str == "empty")
			if (que.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
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