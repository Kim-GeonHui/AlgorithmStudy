#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int N, M;

vector<int> numberArr;
vector<int> resultArr;

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << resultArr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		resultArr[cnt] = numberArr[i];
		DFS(cnt + 1);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	numberArr.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> numberArr[i];
	sort(numberArr.begin(), numberArr.end());

	resultArr.assign(N, 0);

	DFS(0);

	return 0;
}