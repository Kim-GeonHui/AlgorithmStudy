#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int N, M;
vector<int> numberArr;
vector<bool> visitArr;
vector<int> resultArr;

void DFS(int cnt) {

	if (cnt == M) {
		for (int i = 1; i < M + 1; i++) {
			cout << resultArr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i < N + 1; i++) {
		if (visitArr[i])
			continue;

		if (resultArr[cnt] < numberArr[i]) {
			resultArr[cnt + 1] = numberArr[i];
			visitArr[i] = true;
			DFS(cnt + 1);
			visitArr[i] = false;
		}
	}

}

int main() {

	cin >> N >> M;

	numberArr.assign(N + 1, 0);
	for (int i = 1; i < N + 1; i++) {
		cin >> numberArr[i];
	}
	sort(numberArr.begin(), numberArr.end());
	visitArr.assign(N + 1, false);
	resultArr.assign(N + 1, 0);

	DFS(0);

	return 0;
}