#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int Data[1000][1000];

// TopDown
int TopDown(int n, int m, vector<vector<int>>& arr) {

	vector <int> tempData(3);

	if (n - 1 == 0 || m - 1 == 0)
		return Data[n - 1][m - 1];

	if (Data[n - 1][m - 1] == 0) {
		tempData[0] = arr[n - 1][m - 1] + TopDown(n - 1, m, arr);
		tempData[1] = arr[n - 1][m - 1] + TopDown(n, m - 1, arr);
		tempData[2] = arr[n - 1][m - 1] + TopDown(n - 1, m - 1, arr);

		Data[n - 1][m - 1] = max({ tempData[0], tempData[1], tempData[2] });
	}

	return Data[n - 1][m - 1];

}

// BottomUp
int BottomUp(int n, int m, vector<vector<int>>& arr) {

	vector <int> tempData(3);

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			tempData[0] = arr[i][j] + Data[i - 1][j];
			tempData[1] = arr[i][j] + Data[i][j - 1];
			tempData[2] = arr[i][j] + Data[i - 1][j - 1];

			Data[i][j] = max({ tempData[0], tempData[1], tempData[2] });
		}
	}

	return Data[n - 1][m - 1];
}

int main() {

	int N, M;

	cin >> N >> M;

	vector<vector <int>> arr;
	vector <int> tempArr;

	int tempNumber = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tempNumber;
			tempArr.push_back(tempNumber);
		}

		arr.push_back(tempArr);
		tempArr.clear();
	}

	Data[0][0] = arr[0][0];

	for (int i = 1; i < N; i++) {
		Data[i][0] = Data[i - 1][0] + arr[i][0];
	}

	for (int i = 1; i < M; i++) {
		Data[0][i] = Data[0][i - 1] + arr[0][i];
	}

	cout << BottomUp(N, M, arr);

	return 0;
}