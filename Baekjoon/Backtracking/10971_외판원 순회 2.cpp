#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int N;

vector<vector<int>> numberArr;
vector<bool> visitArr;

int frontPoint;
int result = 10000001;

void DFS(int count, int pre, int sum) {
	
	if (count == N) {
		if (numberArr[pre][frontPoint] != 0)
			result = (sum + numberArr[pre][frontPoint] < result) ? sum + numberArr[pre][frontPoint] : result;
		return;
	}
		

	for (int i = 0; i < N; i++) {
		if (visitArr[i])
			continue;

		if (numberArr[pre][i] == 0)
			continue;

		visitArr[i] = true;
		DFS(count + 1, i, sum + numberArr[pre][i]);
		visitArr[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	numberArr.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> numberArr[i][j];
	
	visitArr.assign(N, false);

	for (int i = 0; i < N; i++) {
		frontPoint = i;
		visitArr[i] = true;
		DFS(1, i, 0);
		visitArr[i] = false;
	}

	cout << result;

	return 0;
}