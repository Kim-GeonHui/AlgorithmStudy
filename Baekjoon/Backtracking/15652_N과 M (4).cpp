#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

bool visitArr[9];
int resultArr[9];

int N, M;

void printArr(int arr[]) {
	for (int i = 0; i < M; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void DFS(int count, int index) {
	if (count == M) {
		printArr(resultArr);
		return;
	}

	for (int i = index; i < N + 1; i++) {
		resultArr[count] = i;
		DFS(count + 1, i);
	}
}

int main() {

	cin >> N >> M;
	DFS(0, 1);

	return 0;
}