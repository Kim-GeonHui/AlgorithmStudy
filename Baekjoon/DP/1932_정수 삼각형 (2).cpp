#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<vector<int>> arr;
	vector<int> v(n, 0);
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) 
			cin >> v[j];
		arr.push_back(v);
	}

	ans[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		ans[i][0] = ans[i - 1][0] + arr[i][0];
		ans[i][i] = ans[i - 1][i - 1] + arr[i][i];
	}

	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) 
			ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + arr[i][j];
	}

	int answer = 0;
	for (int i = 0; i < n; i++) answer = max(answer, ans[n - 1][i]);
	cout << answer;

	return 0;
}