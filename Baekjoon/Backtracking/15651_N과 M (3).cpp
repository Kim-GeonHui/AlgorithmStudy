#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

int resultArr[8];

int N, M;

void printArr(int arr[]) {
	for (int i = 0; i < M; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void DFS(int count) {
	if (count == M) {
		printArr(resultArr);
		return;
	}

	for (int i = 1; i < N + 1; i++) {
		resultArr[count] = i;
		DFS(count + 1);
	}
}

int main() {

	cin >> N >> M;
	DFS(0);

	return 0;
}