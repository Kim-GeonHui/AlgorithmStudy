#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

bool visitArr[9];
int resultArr[9];

int N, M;

void DFS(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << resultArr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i < N + 1; i++) {
		if (!visitArr[i]) {
			visitArr[i] = true;
			resultArr[count] = i;
			DFS(count + 1);
			visitArr[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	DFS(0);

	return 0;
}