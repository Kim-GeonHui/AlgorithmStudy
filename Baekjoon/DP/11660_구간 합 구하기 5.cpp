#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> arr(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
		
	vector<vector<int>> ans(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		ans[i][1] = arr[i][1];
		for (int j = 2; j <= N; j++)
			ans[i][j] = ans[i][j - 1] + arr[i][j];
	}

	int x1, x2, y1, y2;
	int answer;
	for (int i = 1; i <= M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		answer = 0;
		for (int j = x1; j <= x2; j++) 
			answer += ans[j][y2] - ans[j][y1 - 1];
		cout << answer << '\n';
	}

	return 0;
}