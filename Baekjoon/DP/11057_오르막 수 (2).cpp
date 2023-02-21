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

	int arr[1001][10];
	for (int i = 0; i < 10; i++) arr[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = arr[i - 1][j];
			for (int k = j + 1; k < 10; k++)
				arr[i][j] += arr[i - 1][k];
			arr[i][j] %= 10007;
		}
	}
	
	int ans = 0;
	for (int num : arr[N]) ans += num;
	cout << ans % 10007;

	return 0;
}