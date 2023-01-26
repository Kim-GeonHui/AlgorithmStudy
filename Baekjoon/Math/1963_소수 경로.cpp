#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	vector<bool> prime(10000, false);
	vector<int> arr;
	queue<int> q;
	string str, next;

	prime[1] = true;
	for (int i = 2; i < 10000; i++) {
		if (prime[i]) continue;
		for (int j = i * i; j < 10000; j += i)
			prime[j] = true;
	}

	int A, B;
	while (T--) {
		cin >> A >> B;
		arr.assign(10000, 0);
		
		q.push(A);
		arr[A] = 1;
		while (!q.empty()) {
			str = to_string(q.front());
			q.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) continue;

					next = str;
					next[i] = char(48 + j);

					if (prime[stoi(next)]) continue;
					if (arr[stoi(next)] != 0) continue;

					arr[stoi(next)] = arr[stoi(str)] + 1;
					q.push(stoi(next));

					if (stoi(next) == B) break;
				}
			}
		}

		while (!q.empty()) q.pop();

		if (arr[B] == 0) cout << 0 << '\n';
		else cout << arr[B] - 1 << '\n';

		arr.clear();
	}

	return 0;
}