#include <stdio.h>
#include <iostream>
#include <deque>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	int N, M;

	deque<int> paperArr;
	deque<int> priorityArr;

	int tempMax;
	int count = 1;
	bool isEnd = 0;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		paperArr.assign(N, 0);
		for (int j = 0; j < N; j++) {
			paperArr[j] = j;
		}
		priorityArr.assign(N, 0);

		for (int j = 0; j < N; j++) {
			cin >> priorityArr[j];
		}

		while (true) {

			tempMax = *max_element(priorityArr.begin(), priorityArr.end());
			if (priorityArr.front() == tempMax) {
				if (paperArr.front() == M) {
					cout << count << '\n';
					break;
				}	

				priorityArr.pop_front();
				paperArr.pop_front();
				count++;
			}
			else {
				paperArr.push_back(paperArr.front());
				paperArr.pop_front();
				priorityArr.push_back(priorityArr.front());
				priorityArr.pop_front();
			}
		}

		paperArr.clear();
		priorityArr.clear();
		count = 1;
	}

	return 0;
}