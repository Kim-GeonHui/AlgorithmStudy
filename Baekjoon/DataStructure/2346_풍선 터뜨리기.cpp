#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N, 0);
	vector<bool> visit(N, 0);
	vector<int> answer(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];

	int count;
	int index = 0;
	int tempIndex = 0;

	answer[0] = 1;
	visit[0] = true;
	for (int i = 0; i < N - 1; i++) {
		count = 0;
		tempIndex = index;

		if (arr[index] < 0) {
			while (count < abs(arr[index])) {
				tempIndex--;
				tempIndex = (tempIndex > 0) ? tempIndex : N - 1;
				if (visit[tempIndex]) continue;
				else count++;
			}
		}
		else {
			while (count < arr[index]) {
				tempIndex++;
				tempIndex = (tempIndex < N) ? tempIndex : 0;
				if (visit[tempIndex]) continue;
				else count++;
			}
		}

		index = tempIndex;
		visit[index] = true;
		answer[i + 1] = index + 1;
	}

	for (int i = 0; i < N; i++) cout << answer[i] << ' ';

	return 0;
}