#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

vector<bool> visitArr(9);
vector<int> resultArr(9);

int N, M;

void printArr(vector<int> arr) {
	for (int i = 0; i < M; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void DFS(int count) {
	for (int i = 1; i < N + 1; i++) {
		if (count == M) {
			printArr(resultArr);
			return;
		}

		if (!visitArr[i]) {
			resultArr[count] = i;
			visitArr[i] = true;
			DFS(count + 1);
			visitArr[i] = false;
		}
	}
}

int main() {

	cin >> N >> M;
	DFS(0);

	return 0;
}