#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

long long int Data[1000];

// TopDown
int TopDown(int n, vector<vector<int>>& arr) {
	
	long long int tempData = 0;

	if (n == 1) {
		return Data[0];
	}

	if (Data[n - 1] == 0) {
		for (int i = 0; i < 10; i++) {
			
		}
	}

	return Data[n - 1];
}

// BottomUp
int BottomUp(int n, vector<vector<int>>& arr) {

	int tempData;

	for (int i = 1; i < n; i++) {
		Data[i] = 0;

		for (int j = 0; j < 10; j++) {

			tempData = 0;

			for (int k = j; k < 10; k++) {
				tempData += arr[i - 1][k];
				arr[i][j] = tempData;
			}

			Data[i] += arr[i][j];
		}

		Data[i] %= 10007;
	}

	return Data[n - 1];
}

int main() {

	int N;

	cin >> N;

	vector <vector <int>> arr(N, vector <int>(10));

	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
	Data[0] = 10;

	cout << BottomUp(N, arr);

	return 0;
}