#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int N, S;

vector<int> numberArr;

int result;

void DFS(int count, int sum) {

	if (count == N) {
		if (sum == S)
			result++;
		return;
	}

	for (int j = 0; j < 2; j++) {
		if (j == 0) {
			DFS(count + 1, sum + numberArr[count]);
		}
		else {
			DFS(count + 1, sum);
		}
	}
} 

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> S;

	numberArr.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> numberArr[i];
	sort(numberArr.begin(), numberArr.end());

	if (S == 0)
		result = -1;
	else
		result = 0;

	DFS(0, 0);

	cout << result;

	return 0;
}