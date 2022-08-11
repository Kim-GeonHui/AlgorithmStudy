#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int N, M;

vector<int> numberArr;
vector<int> tempResultArr;
vector<bool> visitArr;

void DFS(int count) {

	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << tempResultArr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = count + 1; j < M; j++) {
			tempResultArr[j] = 0;
		}

		if (visitArr[i])
			continue;

		if (tempResultArr[count] == numberArr[i])
			continue;

		visitArr[i] = true;
		tempResultArr[count] = numberArr[i];
		DFS(count + 1);
		visitArr[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	numberArr.assign(N + 1, 0);
	tempResultArr.assign(M, 0);
	visitArr.assign(N + 1, 0);
	for (int i = 1; i < N + 1; i++) {
		cin >> numberArr[i];
	}

	sort(numberArr.begin(), numberArr.end());

	DFS(0);
	
	return 0;
}