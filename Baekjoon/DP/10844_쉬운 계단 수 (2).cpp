#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int arr[101][10];
	for (int i = 0; i < 10; i++) arr[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i][0] = arr[i - 1][1];
		arr[i][9] = arr[i - 1][8];
		for (int j = 1; j < 9; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
	}

	long long ans = 0;
	for (int i = 1; i < 10; i++) ans = (ans + arr[N][i]) % 1000000000;
	cout << ans;

	return 0;
}